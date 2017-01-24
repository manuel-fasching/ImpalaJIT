//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_BASIC_EXPRESSION_H_HH
#define IMPALAJIT_BASIC_EXPRESSION_H_HH

#include <expression.h>
#include <algorithm>

class ExpressionNode : public Node
{
public:

    ExpressionNode(class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : Node(_assembly, _expressionContext){
    }
    virtual ~ExpressionNode()
    {
    }

    virtual void evaluate() = 0;

    virtual int getOperator() = 0;

};

class ENConstant : public ExpressionNode
{
    double value;

public:
    explicit ENConstant(double _value, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), value(_value)
    {
    }

    virtual void evaluate()
    {
        assembly.pushConstantToFPUStack(&value);
    }

    virtual int getOperator(){
        return assembly.IDENTITY;
    }

};

class ENVariable : public ExpressionNode
{
    std::string& name;
public:
    explicit ENVariable(std::string& _name, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), name(_name)
    {
    }

    virtual ~ENVariable()
    {
    }

    virtual void evaluate()
    {
        try{
            int index = expressionContext.getIndexOfParameter(name);
            assembly.pushParameterToFPUStack(index);
            return;
        }
        catch(std::exception& e){
        }
        int index = expressionContext.getIndexOfVariable(name);
        assembly.pushLocalVariableToFPUStack(index);
        return;
    }

    virtual int getOperator(){
        return -1;
    }

};

class ENNegate : public ExpressionNode
{
    Node* 	node;

public:
    explicit ENNegate(Node* _node, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), node(_node)
    {
    }

    virtual ~ENNegate()
    {
        delete node;
    }

    virtual void evaluate()
    {
        node->evaluate();
        assembly.operator_=assembly.NEG;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.NEG;
    }
};

class ENAdd : public ExpressionNode
{
    Node* 	left;
    Node* 	right;

public:
    explicit ENAdd(Node* _left, Node* _right , class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), left(_left), right(_right)
    {
    }

    virtual ~ENAdd()
    {
        delete left;
        delete right;
    }

    virtual void evaluate()
    {
        left->evaluate();
        right->evaluate();
        assembly.operator_=assembly.ADD;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.ADD;
    }

};

class ENSubtract : public ExpressionNode
{
    Node* 	left;
    Node* 	right;

public:
    explicit ENSubtract(Node* _left, Node* _right , class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), left(_left), right(_right)
    {
    }

    virtual ~ENSubtract()
    {
        delete left;
        delete right;
    }

    virtual void evaluate()
    {
        left->evaluate();
        right->evaluate();
        assembly.operator_=assembly.SUB;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.SUB;
    }
};

class ENMultiply : public ExpressionNode
{
    Node* 	left;
    Node* 	right;

public:
    explicit ENMultiply(Node* _left, Node* _right, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), left(_left), right(_right)
    {
    }

    virtual ~ENMultiply()
    {
        delete left;
        delete right;
    }

    virtual void evaluate()
    {
        left->evaluate();
        right->evaluate();
        assembly.operator_=assembly.MUL;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.MUL;
    }
};

class ENDivide : public ExpressionNode
{
    Node* 	left;
    Node* 	right;

public:
    explicit ENDivide(Node* _left, Node* _right , class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), left(_left), right(_right)
    {
    }

    virtual ~ENDivide()
    {
        delete left;
        delete right;
    }

    virtual void evaluate()
    {
        left->evaluate();
        right->evaluate();
        assembly.operator_=assembly.DIV;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.DIV;
    }
};

class ENSQRT: public ExpressionNode
{
    Node* 	node;

public:
    explicit ENSQRT(Node* _node, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), node(_node)
    {
    }

    virtual ~ENSQRT()
    {
        delete node;
    }

    virtual void evaluate()
    {
        node->evaluate();
        assembly.operator_=assembly.SQRT;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.SQRT;
    }

};

class ENPower : public ExpressionNode
{
    Node* 	left;
    Node* 	right;

public:
    explicit ENPower(Node* _left, Node* _right, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : ExpressionNode(_assembly, _expressionContext), left(_left), right(_right)
    {
    }

    virtual ~ENPower()
    {
        delete left;
        delete right;
    }

    virtual void evaluate()
    {
        right->evaluate();
        left->evaluate();
        assembly.operator_=assembly.POW;
        assembly.performCalculation();
    }

    virtual int getOperator(){
        return assembly.POW;
    }

};

#endif //IMPALAJIT_BASIC_EXPRESSION_H_HH
