/*
 * HTMLCSSRefAdaptor.h
 *
 *  Created on: 2018-8-9
 *      Author: 1m0nster
 */

#ifndef HTMLCSSREFADAPTOR_H_
#define HTMLCSSREFADAPTOR_H_
#include "gumbo.h"
#include "SelectorsHeader.h"

namespace future {

class HTMLCSSRefAdaptor {
public:
	HTMLCSSRefAdaptor();
	virtual ~HTMLCSSRefAdaptor();
	static bool nodeAdaptToSelector(GumboNode** node, Selector* selector, int *potentialSize = 0);

private:
	static bool nodeAdaptToIDSelector(GumboNode **node, IdSelector* selector);
	static bool nodeAdaptToClassSelector(GumboNode **node, ClassSelector* selector);
	static bool nodeAdaptToTypeSelector(GumboNode **node, TypeSelector* selector);
	static bool nodeAdaptToAttributeSelector(GumboNode **node, AttributeSelector* selector);
	static bool nodeAdaptToPseudoSelector(GumboNode **node, PseudoSelector* selector);
	static bool nodeAdaptToSequenceSelector(GumboNode **node, SequenceSelector* selector);
	static bool nodeAdaptToCombineSelector(GumboNode **node, CombineSelector* selector);
	static bool nodeAdaptToGroupSelector(GumboNode **node, GroupSelector* selector);
};

}

#endif /* HTMLCSSREFADAPTOR_H_ */
