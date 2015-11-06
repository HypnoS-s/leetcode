#pragma once
#include "ListNode.h"

void deleteNode(ListNode* node) {
	std::swap(*node, *node->next);
}
