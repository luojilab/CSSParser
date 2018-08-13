//
//  CSSLex.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef CSSLex_hpp
#define CSSLex_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "CSSLexStatus.h"

namespace future {
    class Lex {
    public:
        struct CSSToken {
            CSSTokenType type;
            const char* data;
            CSSToken()
            {
            	data = 0;
            }
            ~CSSToken()
            {
                delete [] data;
                data = 0;
            }
        };
    public:
        static Lex*     GetLex();
        CSSToken*       GetToken();
        void            CleanResource();
        void            SetBufferSource(const std::string fileName);
    private:
        Lex();
        ~Lex();
        CSSToken*   GetIdentToken();
        CSSToken*   GetTextToken(char stringType);
        bool        isDigitalCharacter(char);
        bool        isLetter(char);
        bool        isHexCharacter(char);
        bool        isWs(char);
        const char* copyData(CSSToken* from);
    private:
        std::string             m_fileName;
        const char*             m_buffer;
        size_t                  m_bufferSize;
        size_t                  m_firstPos;
        size_t                  m_forwardPos;
        std::vector<CSSToken *> m_tokenCache;
    };
}
#endif /* CSSLex_hpp */
