//
// Created by manuel on 26.12.16.
//

#ifndef IMPALAJIT_BOOL_H
#define IMPALAJIT_BOOL_H

#include <comparison_expression.h>

class BooleanNode : public Node {
    Node* node;

public:
    BooleanNode(Node* _node,  class Assembly& _assembly)
            : Node(_assembly), node(_node)
    {
    }

    virtual ~BooleanNode()
    {
        delete node;
    }

    virtual void evaluate(){
        node->evaluate();
    }

    virtual int getOperator(){
        return node->getOperator();
    }
};

class BooleanJunctionNode : public Node {
    Node* left;
    Node* right;
    int boolOperator;


public:
    int* label1;
    int* label2;
    BooleanJunctionNode(Node* _left, Node* _right, int _boolOperator, class Assembly& _assembly)
            : Node(_assembly), left(_left), right(_right), boolOperator(_boolOperator)
    {
    }

    BooleanJunctionNode(Node* _left, class Assembly& _assembly)
            : Node(_assembly), left(_left), boolOperator(assembly.AND)
    {
    }

    virtual ~BooleanJunctionNode()
    {
        delete left;
        delete right;
    }

    virtual void evaluate(){
        if(right != NULL) {
            if (right->getOperator() == assembly.AND && boolOperator == assembly.OR) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
                assembly.addLocalLabel(*label2);
                (*label2)--;
            } else if (right->getOperator() == assembly.OR && boolOperator == assembly.AND) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
                assembly.addLocalLabel(*label1);
                (*label1)++;
            } else if (right->getOperator() == boolOperator) {
                ((BooleanJunctionNode *) right)->label1 = label1;
                ((BooleanJunctionNode *) right)->label2 = label2;
                right->evaluate();
            } else if (right->getOperator() != assembly.OR && right->getOperator() != assembly.AND) {
                right->evaluate();
                assembly.operator_ = right->getOperator();
                if (boolOperator == assembly.OR)
                    assembly.conditionalJumpForwardTo(*label1, true);
                else
                    assembly.conditionalJumpForwardTo(*label2, false);
            }
        }
        if (left->getOperator() == assembly.AND && boolOperator == assembly.OR) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
            assembly.addLocalLabel(*label2);
            (*label2)--;
        } else if (left->getOperator() == assembly.OR && boolOperator == assembly.AND) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
            assembly.addLocalLabel(*label1);
            (*label1)++;
        } else if (left->getOperator() == boolOperator) {
            ((BooleanJunctionNode *) left)->label1 = label1;
            ((BooleanJunctionNode *) left)->label2 = label2;
            left->evaluate();
        } else if (left->getOperator() != assembly.OR && left->getOperator() != assembly.AND) {
            left->evaluate();
            assembly.operator_ = left->getOperator();
            if (boolOperator == assembly.OR) {
                assembly.conditionalJumpForwardTo(*label1, true);
                assembly.jumpForwardTo(*label2);
            } else
                assembly.conditionalJumpForwardTo(*label2, false);
        }


    }

    virtual int getOperator(){
        return boolOperator;
    }
};

#endif //IMPALAJIT_BOOL_H
