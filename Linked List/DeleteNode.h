#pragma once
#include "ListNode.h"

class Solution {
public:
	void deleteNode(ListNode* node) {
		std::swap(*node, *node->next);
	}
};