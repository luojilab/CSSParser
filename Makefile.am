lib_LIBRARIES = libcssparser.a
libcssparser_a_SOURCES = \
												 src/CSSParser/CSSParser.cpp\
												 src/CSSParser/CSSLex.cpp\
												 src/CSSParser/Keyword/KeywordItem.cpp\
												 src/CSSParser/Selectors/ClassSelector.cpp\
												 src/CSSParser/Selectors/PseudoSelector.cpp\
												 src/CSSParser/Selectors/SelectorGroup.cpp\
												 src/CSSParser/Selectors/SignSelector.cpp\
												 src/CSSParser/Selectors/CombineSelector.cpp\
												 src/CSSParser/Selectors/AttributeSelector.cpp\
												 src/CSSParser/Selectors/SelectorSequence.cpp\
												 src/CSSParser/Selectors/UniversalSelector.cpp\
												 src/CSSParser/Selectors/TypeSelector.cpp\
												 src/CSSParser/Selectors/Selector.cpp\
												 src/CSSParser/Selectors/IdSelector.cpp\
												 src/Applicability/HTMLCSSRefAdaptor.cpp\
                                                 src/Applicability/PseudoSelectorRefChiefJudge.cpp\
												 src/Vendor/gumbo/string_buffer.c\
												 src/Vendor/gumbo/util.c\
												 src/Vendor/gumbo/vector.c\
												 src/Vendor/gumbo/attribute.c\
												 src/Vendor/gumbo/UrlUtil.cpp\
												 src/Vendor/gumbo/char_ref.c\
												 src/Vendor/gumbo/utf8.c\
												 src/Vendor/gumbo/error.c\
												 src/Vendor/gumbo/tag.c\
												 src/Vendor/gumbo/GumboInterface.cpp\
												 src/Vendor/gumbo/parser.c\
												 src/Vendor/gumbo/tokenizer.c\
												 src/Vendor/gumbo/string_piece.c\
												 src/Vendor/gumbo/gumbo_edit.c\
												 src/Vendor/Utils/ContainerUtil.cpp\
												 src/Vendor/Utils/StringUtil.cpp

bin_PROGRAMS = example
libcssparser_a_CPPFLAGS = \
													-Isrc/Applicability\
													-Isrc/CSSParser\
													-Isrc/CSSParser/Keyword\
													-Isrc/CSSParser/Selectors\
													-Isrc/Vendor/gumbo\
													-Isrc/Vendor/Utils
example_CPPFLAGS =\
                  -Isrc/Applicability\
									-Isrc/CSSParser\
									-Isrc/CSSParser/Keyword\
									-Isrc/CSSParser/Selectors\
									-Isrc/Vendor/gumbo\
									-Isrc/Vendor/Utils
example_SOURCES = examples/main.cpp
example_DEPENDENCIES = libcssparser.a
example_LDADD = libcssparser.a
