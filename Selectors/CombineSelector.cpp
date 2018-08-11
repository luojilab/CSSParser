//
//  CombineSelector.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "CombineSelector.hpp"

namespace future {
    
    void cleanListElement(std::list<Selector *>list)
    {
        auto it = list.begin();
        auto end = list.end();
        while (it != end) {
            delete *it++;
        }
        list.clear();
    }
    
    CombineSelector::~CombineSelector()
    {
        cleanListElement(m_normalSiblingList);
        cleanListElement(m_instanceSiblingList);
        cleanListElement(m_normalInhericalList);
        cleanListElement(m_instanceSiblingList);
    }
    
    void CombineSelector::initialNormalSiblingList(future::Selector *head, future::Selector *sibling)
    {
        if (!head || !sibling) {
            return;
        }
        cleanListElement(m_normalSiblingList);
        m_normalSiblingList.clear();
        m_normalSiblingList.push_back(head);
        m_normalSiblingList.push_back(sibling);
    }
    
    void CombineSelector::initialInstanceSiblingList(future::Selector *head, future::Selector *sibling)
    {
        if (!head || !sibling) {
            return;
        }
        cleanListElement(m_instanceSiblingList);
        m_instanceSiblingList.clear();
        m_instanceSiblingList.push_back(head);
        m_instanceSiblingList.push_back(sibling);
    }
    
    void CombineSelector::initialNormalInhericalList(future::Selector *root, future::Selector *child)
    {
        if (!root || !child) {
            return;
        }
        cleanListElement(m_normalInhericalList);
        m_normalInhericalList.clear();
        m_normalInhericalList.push_back(root);
        m_normalInhericalList.push_back(child);
    }
    
    void CombineSelector::initialInstanceInhericalList(future::Selector *root, future::Selector *child)
    {
        if (!root || !child) {
            return;
        }
        cleanListElement(m_instanceInhericalList);
        m_instanceInhericalList.clear();
        m_instanceInhericalList.push_back(root);
        m_instanceInhericalList.push_back(child);
    }

    bool CombineSelector::isBaseSelector()
    {
    	return false;
    }

    int CombineSelector::weight()
    {
    	int w = 0;
    	std::list<Selector *>::iterator one;
    	std::list<Selector *>::iterator other;
    	do {
    		if (m_normalInhericalList.size() == 2) {
    			one = m_normalInhericalList.begin();
    			other = --m_normalInhericalList.end();
    			break;
    		}
    		if (m_instanceInhericalList.size() == 2) {
    			one = m_instanceInhericalList.begin();
    			other = --m_instanceInhericalList.end();
    			break;
    		}
    		if (m_normalSiblingList.size() == 2) {
    			one = m_normalSiblingList.begin();
    			other = --m_normalSiblingList.end();
    			break;
    		}
    		if (m_instanceSiblingList.size() == 2) {
    			one = m_instanceSiblingList.begin();
    			other = --m_instanceSiblingList.end();
    			break;
    		}
    	} while (0);
    	if (!*one || !*other) {
    		return w;
    	}
    	w += (*one)->weight() + (*other)->weight();
    	return w;
    }

    Selector* CombineSelector::getBefore()
    {
    	std::list<Selector *>::iterator before;
    	do {
    		if (m_normalInhericalList.size() == 2) {
    			before = m_normalInhericalList.begin();
    			break;
    		}
    		if (m_instanceInhericalList.size() == 2) {
    			before = m_instanceInhericalList.begin();
    			break;
    		}
    		if (m_normalSiblingList.size() == 2) {
    			before = m_normalSiblingList.begin();
    			break;
    		}
    		if (m_instanceSiblingList.size() == 2) {
    			before = m_instanceSiblingList.begin();
    			break;
    		}
    	} while (0);
    	return *before;
    }

    Selector* CombineSelector::getAfter()
    {
    	std::list<Selector *>::iterator after;
    	do {
    		if (m_normalInhericalList.size() == 2) {
    			after = --m_normalInhericalList.end();
    			break;
    		}
    		if (m_instanceInhericalList.size() == 2) {
    			after = --m_instanceInhericalList.end();
    			break;
    	    }
    		if (m_normalSiblingList.size() == 2) {
    			after = --m_normalSiblingList.end();
    			break;
    		}
    		if (m_instanceSiblingList.size() == 2) {
    			after = --m_instanceSiblingList.end();
    			break;
    		}
    	} while (0);
    	return *after;
    }

} // namespace future
