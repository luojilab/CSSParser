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
    typedef GumboNode*** GumboArrayPtr;
    typedef GumboNode** GumboArray;
	HTMLCSSRefAdaptor();
	virtual ~HTMLCSSRefAdaptor();
	static bool nodeAdaptToSelector(GumboArrayPtr node, Selector* selector, int *potentialSize = 0);

private:
	static bool nodeAdaptToIDSelector(GumboArrayPtr node, IdSelector* selector, int *potentialSize);
	static bool nodeAdaptToClassSelector(GumboArrayPtr node, ClassSelector* selector, int *potentialSize);
	static bool nodeAdaptToTypeSelector(GumboArrayPtr node, TypeSelector* selector, int *potentialSize);
	static bool nodeAdaptToAttributeSelector(GumboArrayPtr node, AttributeSelector* selector, int *potentialSize);
	static bool nodeAdaptToPseudoSelector(GumboArrayPtr node, PseudoSelector* selector, int *potentialSize);
	static bool nodeAdaptToSequenceSelector(GumboArrayPtr node, SequenceSelector* selector, int *potentialSize);
	static bool nodeAdaptToCombineSelector(GumboArrayPtr node, CombineSelector* selector, int *potentialSize);
	static bool nodeAdaptToGroupSelector(GumboArrayPtr node, GroupSelector* selector, int *potentialSize);
    static void updateNextNodes(const std::list<GumboNode *>&, GumboArrayPtr arrayPtr, int *size);
};

}

#endif /* HTMLCSSREFADAPTOR_H_ */
