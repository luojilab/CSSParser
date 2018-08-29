//
//  AttributeSelector.cpp
//  DDCSSParser
//
//  Created by 1m0nster on 2018/8/7.
//  Copyright © 2018 1m0nster. All rights reserved.
//

#include "AttributeSelector.hpp"

namespace future {
	bool AttributeSelector::isBaseSelector()
	{
		return true;
	}

	int AttributeSelector::weight()
	{
		return 10;
	}
}
