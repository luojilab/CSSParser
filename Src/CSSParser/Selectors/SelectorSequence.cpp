//
//  SelectorSequence.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "SelectorSequence.hpp"

namespace future {
    void SequenceSelector::appendSelector(Selector *s)
    {
        if (!s) {
            return;
        }
        m_selectors.push_back(s);
    }
    
    SequenceSelector::~SequenceSelector()
    {
        auto it = m_selectors.begin();
        auto end = m_selectors.end();
        while (it != end) {
            delete *it++;
        }
        m_selectors.clear();
    }

    bool SequenceSelector::isBaseSelector()
    {
    	return false;
    }

    int SequenceSelector::weight()
    {
    	auto it = m_selectors.begin();
    	auto end  = m_selectors.end();
    	int w = 0;
    	while(it != end) {
    		w += (*it++)->weight();
    	}
    	return w;
    }
}
