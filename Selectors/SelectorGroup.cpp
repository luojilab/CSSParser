//
//  SelectorGroup.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "SelectorGroup.hpp"

namespace future {
    
    void GroupSelector::addSelector(future::Selector *s)
    {
        if (!s) {
            return ;
        }
        m_slectors.push_back(s);
    }
    
    GroupSelector::~GroupSelector()
    {
        auto it = m_slectors.begin();
        auto end = m_slectors.end();
        while (it != end) {
            delete *it++;
        }
        m_slectors.clear();
    }

    bool GroupSelector::isBaseSelector()
    {
    	return false;
    }

    int GroupSelector::weight()
    {
    	auto it = m_slectors.begin();
    	auto end = m_slectors.end();
    	int w = 0;
    	while(it != end) {
    		w += (*it++)->weight();
    	}
    	return w;
    }
}
