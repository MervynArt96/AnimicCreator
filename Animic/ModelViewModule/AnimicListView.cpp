#include "stdafx.h"
#include "AnimicListView.h"

AnimicListView::AnimicListView()
{
	setMovement(QListView::Free);
}

AnimicListView::~AnimicListView()
{
}

void AnimicListView::setListMode(bool x)
{
	mode = x;
}