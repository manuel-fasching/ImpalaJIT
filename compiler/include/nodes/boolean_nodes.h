//
// Created by manuel on 26.12.16.
//

#ifndef IMPALAJIT_BOOL_H
#define IMPALAJIT_BOOL_H

#include <node.h>

/*
class BooleanNode : public Node {
    Node* node;

public:
    BooleanNode(Node* _node)
            : Node(), node(_node)
    {
    }

    virtual ~BooleanNode()
    {
        delete node;
    }

    virtual void evaluate(){
        node->evaluate();
    }
};*/

class BooleanJunctionNode : public Node {
private:
    Node* left;
    Node* right;

public:
    BooleanJunctionType boolOperator;
    int* label1;
    int* label2;
    BooleanJunctionNode(Node* _left, Node* _right, BooleanJunctionType _boolOperator)
            : Node(BOOLEAN_JUNCTION), boolOperator(_boolOperator), left(_left), right(_right)
    {
        nodes.push_back(left);
        nodes.push_back(right);
    }

    BooleanJunctionNode(Node* _left)
            : Node(BOOLEAN_JUNCTION), left(_left), boolOperator(AND)
    {
        nodes.push_back(left);
    }

    virtual ~BooleanJunctionNode()
    {
        delete label1;
        delete label2;
        delete left;
        delete right;
        label1 = NULL;
        label2 = NULL;
        left = NULL;
        right = NULL;
    }
/*
    virtual void evaluate(){
        if(right != NULL) {
            if (right->getType() == assembly.AND && boolOperator == assembly.OR) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
                //assembly.addLocalLabel(*label2);
                //(*label2)--;
            } else if (right->getType() == assembly.OR && boolOperator == assembly.AND) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
                assembly.addLocalLabel(*label1);
                (*label1)++;
            } else if (right->getType() == boolOperator) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
            } else if (right->getType() != assembly.OR && right->getType() != assembly.AND) {
                right->evaluate();
                assembly.operator_ = right->getType();
                if (boolOperator == assembly.OR) {
                    assembly.conditionalJumpForwardTo(*label1, true);
                }
                else {
                    assembly.conditionalJumpForwardTo(*label2, false);
                }
            }
        }
        if (left->getType() == assembly.AND && boolOperator == assembly.OR) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
            //assembly.addLocalLabel(*label2);
            //(*label2)--;
        } else if (left->getType() == assembly.OR && boolOperator == assembly.AND) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
            assembly.addLocalLabel(*label1);
            (*label1)++;
        } else if (left->getType() == boolOperator) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
        } else if (left->getType() != assembly.OR && left->getType() != assembly.AND) {
            left->evaluate();
            assembly.operator_ = left->getType();
            if (boolOperator == assembly.OR) {
                assembly.conditionalJumpForwardTo(*label1, true);
                assembly.jumpForwardTo(*label2);
            }
            else {
                assembly.conditionalJumpForwardTo(*label2, false);
            }
        }


    } */
};

#endif //IMPALAJIT_BOOL_H
