#include "MD5.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace MD5;
using namespace std;

#define BUFFER_SIZE 1024

MD5MeshParser::MD5MeshParser()
{
  m_keyWordParser.init();
  m_intParser.init();
  m_state = KEY_WORD;
}

int MD5MeshParser::parseMD5File(const char* filename)
{
  FILE* pFile;
  uint read_size;

  pFile = fopen(filename, "rb");
  if (pFile == NULL)
    {
      perror("Failed to open file \"%s\"");
      return -1;
    }
  char readBuffer[BUFFER_SIZE];

  while(true)
    {
      read_size = fread(readBuffer, sizeof(char), BUFFER_SIZE, pFile);
      feed(readBuffer, read_size);
      if (read_size < BUFFER_SIZE) break;
    }

  return 0;
}

void MD5MeshParser::feed(const char *data, uint length)
{
  for (int i = 0; i < length; i++)
    {
      if (m_state == KEY_WORD && m_keyWordParser.putChar(data[i]) == 1)
        {
          if (m_keyWordParser.getKeyWord() == "MD5Version")
            {
              m_state = MD5_VERSION;
            }
        }
      if (m_state == MD5_VERSION && m_intParser.putChar(data[i]) == 1)
        {
          cout << "MD5_VERSION: " <<  m_intParser.getNumber();
        }
    }
}
