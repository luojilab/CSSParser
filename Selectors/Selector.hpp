//
//  Selector.hpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#ifndef Selector_hpp
#define Selector_hpp

#include <stdio.h>
#include <iostream>

namespace future {
    class Selector {
        friend class CombineSelector;
    public:
        enum SelectorType {
            TypeSelector,
            IDSelector,
            ClassSelector,
            UniversalSelector,
            AttributeSelector,
            PseudoSelector,
            SimpleSelectorSequence,
            CombineSelector,
            SelectorGroup,
            SignSelector
        };
    public:
        Selector();
        virtual ~Selector() = 0;
        inline const char* getRuleData()
        {
            return m_ruleData;
        }
        
        void setRuleData(const char *data)
        {
            m_ruleData = data;
        }
        
        SelectorType getType()
        {
            return m_selectorType;
        }
        
       virtual bool isBaseSelector() = 0;
       virtual int weight() = 0;

        virtual std::string description();
    protected:
        SelectorType m_selectorType;
        const char* m_ruleData;
    };
}

#endif /* Selector_hpp */
