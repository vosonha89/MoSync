/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

@interface AbstractLayoutView : UIScrollView
{
    int spacing;
    int leftMargin, rightMargin;
    int topMargin, bottomMargin;
    UIControlContentHorizontalAlignment hAlignment;
    UIControlContentVerticalAlignment vAlignment;
}

- (id)init;
- (id)initWithFrame:(CGRect)frame;
- (id)initWithFrame:(CGRect)frame spacing:(int)s;
- (id)initWithFrame:(CGRect)frame spacing:(int)s leftMargin:(int)lm
    rightMargin:(int)rm topMargin:(int)tm bottomMargin:(int)bm;
// UIControlContentHorizontalAlignmentFill and
// UIControlContentVerticalAlignmentFill are not supported, since layout
// managers do not manage subviews sizes.
- (id)initWithFrame:(CGRect)frame spacing:(int)s leftMargin:(int)lm
    rightMargin:(int)rm topMargin:(int)tm bottomMargin:(int)bm
    hAlignment:(UIControlContentHorizontalAlignment)ha
    vAlignment:(UIControlContentVerticalAlignment)va;

// These functions set the layout view's size to sizeThatFits: (without resizing
// the subviews). The caller can override one of the dimensions.
- (void)setSize;
- (void)setSizeWithWidth:(int)w;
- (void)setSizeWithHeight:(int)h;

// Returns frame width / height minus margins.
- (int)availableWidth;
- (int)availableHeight;

- (void)scrollToShow:(UIView *)subview animated:(BOOL)animated;

- (CGSize)layoutSubviewsEffectively:(BOOL)effectively;

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
@end
