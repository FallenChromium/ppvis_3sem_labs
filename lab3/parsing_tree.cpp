#include "parsing_tree.hpp"
#include <algorithm>

Node::Node()
{
    this->parent = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Node::Node(std::set<std::string> val): value(val)
{
    this->parent = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

void Node::insert_left(std::set<std::string> left_value) { this->left_child = std::make_shared<Node>(left_value); }

void Node::insert_right(std::set<std::string> right_value) { this->right_child = std::make_shared<Node>(right_value); }


std::set<std::string> Union_node::evaluate()
{
    if (left_child == nullptr && right_child == nullptr) return value;
    std::set<std::string> set1 = left_child->evaluate();
    std::set<std::string> set2 = right_child->evaluate();
    std::set<std::string> result;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.end()));
    return result;
}


std::set<std::string> Intersect_node::evaluate()
{
    if (left_child == nullptr && right_child == nullptr) return value;
    std::set<std::string> set1 = left_child->evaluate();
    std::set<std::string> set2 = right_child->evaluate();
    std::set<std::string> result;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.end()));
    return result;
}

std::set<std::string> Diff_node::evaluate()
{
    if (left_child == nullptr && right_child == nullptr) return value;
    std::set<std::string> set1 = left_child->evaluate();
    std::set<std::string> set2 = right_child->evaluate();
    std::set<std::string> result;
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.end()));
    return result;
}
