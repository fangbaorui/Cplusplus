#include "FileCompress.h"
FileCompress::FileCompress()
{
	for (size_t i = 0; i < 256; ++i)
	{
		fileInfo[i].ch = (uchar)i;
		fileInfo[i].appearCount = 0;
	}
}

bool FileCompress::CompressFile(const std::string& strFilePath)
{
	// 1. ͳ��Դ�ļ���ÿ���ֽڳ��ֵĴ���
	FILE* pf = fopen(strFilePath.c_str(), "rb");
	if (NULL == pf)
	{
		return false;
	}

	uchar readBuff[1024];
	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, pf);
		if (0 == rdsize)
			break;

		for (size_t i = 0; i < rdsize; ++i)
		{
			// ͳ��
			fileInfo[readBuff[i]].appearCount++;
		}
	}

	// 2. ����huffman��
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, 256, invalid);

	// 3. ����huffman����ÿ���ֽڵı���
	GenerateCode(ht.GetRoot());

	// 4. ��Ҫд���ѹ��ʱ��Ҫ�õ�����Ϣ
	FILE* fOut = fopen("2.txt", "wb");
	if (NULL == fOut)
	{
		fclose(pf);
		return false;
	}
	WriteFileHead(fOut, strFilePath);

	// 5. �����ҵ��ı����дԴ�ļ�---дѹ������

	uchar chBit = 0;   // ��������ת������Ķ����Ʊ���λ
	uchar bitCount = 0; // chBit�з����˼�������λ

	// 1. ��ȡԴ�ļ��е�����
	fseek(pf, 0, SEEK_SET);
	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, pf);
		if (0 == rdsize)
			break;

		// 2. ����ֽ�������ת��
		for (size_t i = 0; i < rdsize; ++i)
		{
			auto& strCode = fileInfo[readBuff[i]].strCode;

			// 3. �����ֽڶ�Ӧ���ַ������Զ����Ƹ�ʽ��֯--chBit
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				chBit <<= 1;   // chBitĩβ�����һ������0
				if ('1' == strCode[j])
					chBit |= 1;

				bitCount++;
				if (8 == bitCount)
				{
					// chBit ����8������λ�Ѿ��������
					fputc(chBit, fOut);
					chBit = 0;
					bitCount = 0;
				}
			}
		}
	}

	if (bitCount > 0 && bitCount < 8)
	{
		chBit <<= (8 - bitCount);
		fputc(chBit, fOut);
	}

	fclose(pf);
	fclose(fOut);
	return true;
}

void FileCompress::WriteFileHead(FILE* fOut, const std::string& filePath)
{
	// 1. ����Դ�ļ��ĺ�׺
	// xxx.txt
	// D:\FileCompress\FileCompress\xxx.txt
	std::string postFix = filePath.substr(filePath.rfind('.'));
	postFix += "\n";
	fwrite(postFix.c_str(), 1, postFix.size(), fOut);

	// 2. �����ֽ�Ƶ����Ϣ�ܵ�����

	// 3. ����ÿ�е��ַ�Ƶ����Ϣ

	std::string charAppear;
	size_t szLineCount = 0;
	for (auto& e : fileInfo)
	{
		// �����ִ�����0�ε��ַ����ַ������ִ���\n
		if (e.appearCount > 0)
		{
			charAppear += e.ch;
			charAppear += ",";  // A,
			charAppear += std::to_string(e.appearCount);   // 1234 ---> "1234"
			charAppear += "\n";
			szLineCount++;
		}  // A,1\nB,3\nC,5\nD,7\n
	}

	std::string strLineCount = std::to_string(szLineCount);
	strLineCount += "\n";
	fwrite(strLineCount.c_str(), 1, strLineCount.size(), fOut);
	fwrite(charAppear.c_str(), 1, charAppear.size(), fOut);
}

void FileCompress::GenerateCode(HTNode<CharInfo>* root)
{
	if (NULL == root)
		return;

	if (NULL == root->left && NULL == root->right)
	{
		// ��Ҷ��һֱ����ڵ㷽���ƶ��ұ���
		HTNode<CharInfo>* cur = root;
		HTNode<CharInfo>* parent = cur->parent;

		auto& strCode = fileInfo[cur->weight.ch].strCode;
		while (parent)
		{
			if (cur == parent->left)
				strCode += '0';
			else
				strCode += '1';

			cur = parent;
			parent = cur->parent;
		}

		reverse(strCode.begin(), strCode.end());
	}

	GenerateCode(root->left);
	GenerateCode(root->right);
}

bool FileCompress::UNCompressFile(const std::string& strFilePath)
{
	FILE* fIn = fopen(strFilePath.c_str(), "rb");

	// ��ȡ��ѹ����Ҫ����Ϣ---һ�ζ�ȡһ�е�����
	std::string szContent;
	GetLine(fIn, szContent);
	std::string postFix = szContent;

	szContent = "";
	GetLine(fIn, szContent);   // "4"

	size_t lineCount = atoi(szContent.c_str());
	for (size_t i = 0; i < lineCount; ++i)
	{
		szContent = "";
		GetLine(fIn, szContent);  // "A,1"
		if (szContent == "")
		{
			// ��������\n
			szContent += "\n";
			GetLine(fIn, szContent);
		}

		uchar ch = szContent[0];
		fileInfo[ch].appearCount = atoi(szContent.c_str() + 2);
	}

	// ��ԭhuffman
	HuffmanTree<CharInfo> ht;
	CharInfo invalid;
	invalid.appearCount = 0;
	ht.CreateHuffmanTree(fileInfo, sizeof(fileInfo) / sizeof(fileInfo[0]), invalid);

	std::string fileName("3");
	fileName += postFix;
	FILE* fOut = fopen(fileName.c_str(), "wb");

	// ��ѹ��
	uchar readBuff[1024];
	HTNode<CharInfo>* cur = ht.GetRoot();
	size_t filesize = cur->weight.appearCount;
	size_t unCompressSize = 0;
	while (true)
	{
		// ��ȡѹ������
		size_t rdsize = fread(readBuff, 1, 1024, fIn);
		if (0 == rdsize)
			break;

		// �����rdBuff�е�ÿ���ֽڽ��н���
		// ���ո��ֽ��еĶ����Ʊ���λ--�Ӹ�λ����λ�������λ����
		// ���������ǰ��ձ���λ��ֵȥ����huffman��--һֱ������Ҷ�ӽڵ��λ��
		for (size_t i = 0; i < rdsize; ++i)
		{
			// rdBuff[i]
			uchar ch = readBuff[i];
			for (size_t j = 0; j < 8; ++j)
			{
				// ���ch�����1����0
				if (ch & 0x80)
					cur = cur->right;
				else
					cur = cur->left;

				ch <<= 1;

				if (NULL == cur->left && NULL == cur->right)
				{
					// curһ����Ҷ�ӽڵ�
					fputc(cur->weight.ch, fOut);
					cur = ht.GetRoot();
					unCompressSize++;
					if (filesize == unCompressSize)
						break;
				}
			}
		}
	}

	fclose(fIn);
	fclose(fOut);
	return true;
}



// �����л�ȡ�ļ�������
void FileCompress::GetLine(FILE* fIn, std::string& szContent)
{
	while (!feof(fIn))
	{
		uchar ch = fgetc(fIn);
		if (ch == '\n')
			return;

		szContent += ch;
	}
}

