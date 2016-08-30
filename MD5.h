#ifndef MD5_H
#define MD5_H
#include <iostream>
using namespace std;
namespace MD5 {
  typedef unsigned int uint;

  class KeyWordParser {
  private:
    enum KeyWordStateEnum { SKIPING_WHITESPACE, PARSING, FINISHED };
    string m_keyWord;
    KeyWordStateEnum m_state;
  public:
    void init ()
    {
      m_state = SKIPING_WHITESPACE;
      m_keyWord.clear();
    }

    int putChar(char c)
    {
      if (m_state == FINISHED)
        {
          return -1;
        }
      if (isspace(c) && m_state == SKIPING_WHITESPACE)
        {
          return 0;
        }
      if (isspace(c) && m_state == PARSING)
        {
          m_state = FINISHED;
          return 1;
        }
      if (isgraph(c))
        {
          m_keyWord += c;
          m_state = PARSING;
          return 0;
        }

    }

    string getKeyWord()
    {
      if (m_state == FINISHED) return m_keyWord;
    }
  };

  class IntParser {
  private:
    enum IntParserStateEnum { SKIPING_WHITESPACE, PARSING, FINISHED };
    string m_s_number;
    int m_number;
    IntParserStateEnum m_state;
  public:
    void init ()
    {
      m_state = SKIPING_WHITESPACE;
      m_s_number.clear();
    }

    int putChar(char c)
    {
      if (m_state == FINISHED)
        {
          return -1;
        }
      if (isspace(c) && m_state == SKIPING_WHITESPACE)
        {
          return 0;
        }
      if (isspace(c) && m_state == PARSING)
        {
          m_state = FINISHED;
          m_number = atoi(m_s_number.c_str());
          return 1;
        }
      if (isalnum(c)||((c = '-' || c == '+') && m_state == SKIPING_WHITESPACE))
        {
          m_s_number += c;
          m_state = PARSING;
          return 0;
        }

    }

    int getNumber()
    {
      if (m_state == FINISHED) return m_number;
    }

  };

  class MD5Mesh {


  };

  class MD5Anim{

  };

  class MD5MeshParser {
    enum MD5MeshParserStateEnum { KEY_WORD, MD5_VERSION};
    KeyWordParser m_keyWordParser;
    MD5MeshParserStateEnum m_state;
    IntParser m_intParser;
  public:
    MD5MeshParser();
    int parseMD5File(const char* filename);
    void feed(const char* data, uint length);
  };
}
#endif
