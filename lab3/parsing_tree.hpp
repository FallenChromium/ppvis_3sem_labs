#ifndef _TREE_H_
#define _TREE_H_
#include <cstddef>
#include <memory>
#include <iostream>
#include <set>


enum Operators
{
    UNION = '+',
    INTERSECT = '*',
    SYMM_DIFF = '-'
};

class Node
{
    protected:
        std::shared_ptr<Node> parent;
        std::shared_ptr<Node> left_child;
        std::shared_ptr<Node> right_child;
        std::set<std::string> value;
    public:
        Node();
        Node(std::set<std::string>);
        void insert_left(std::set<std::string>);
        void insert_right(std::set<std::string>);
        void set_parent(std::shared_ptr<Node> parent) { this->parent = parent; };
        void set_left_child(std::shared_ptr<Node> new_child) { this->left_child = new_child; };
        void set_right_child(std::shared_ptr<Node> new_child) { this->right_child = new_child; };
        void set_value (std::set<std::string> new_value) { this->value = new_value; };
        std::shared_ptr<Node> get_parent() { return this->parent; };
        std::shared_ptr<Node> get_left_child() { return this->left_child; };
        std::shared_ptr<Node> get_right_child() { return this->right_child; };
        std::set<std::string> get_value() { return this->value; };
        virtual std::set<std::string> evaluate() {return value;};
};


class Union_node : public Node
{
    public:
        Union_node(): Node() {};
        std::set<std::string> evaluate() override;
};


class Intersect_node : public Node
{
    public:
        Intersect_node(): Node() {};
        std::set<std::string> evaluate() override;
};


class Diff_node : public Node
{
    public:
        Diff_node(): Node() {};
        std::set<std::string> evaluate() override;
};

class Equals_node : public Node {
    public:
        Equals_node() : Node() {};
        std::set<std::string> evaluate() override;
};
#endif