#pragma once

#include <memory>

class Node;
using NodePtr = std::shared_ptr<Node>;

class ComparableData;
using ComparableDataUPtr = std::unique_ptr<ComparableData>;