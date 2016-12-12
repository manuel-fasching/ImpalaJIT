// $Id$
/** \file expression.h Implements an example calculator class group. */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>
#include <assembly.hh>
#include <stdio.h>

/** ExpressionNode is the abstract base class for expression nodes. From it the
 * different nullary, unary and binary nodes are derived. */
class ExpressionNode
{
protected:
    /** Reference to the assembly class. */
    class Assembly& assembly;
public:

    ExpressionNode(class Assembly& _assembly) :
            assembly(_assembly){
    }
    /// required for virtual functions. in the derived classes the operands are
    /// deleted.
    virtual ~ExpressionNode()
    {
    }

    /// evaluate the complete calculation tree and return the floating point
    /// result value
    virtual void evaluate() = 0;

    /// output the expression tree to the given stream. tries to format the
    /// output to make tree levels visible.
    virtual void	print(std::ostream &os, unsigned int depth=0) const = 0;

    /// helper function for print() which makes the indention string
    static inline std::string indent(unsigned int d)
    {
	return std::string(d * 2, ' ');
    }
};

/** Expression node always returning a constant value. */
class ENConstant : public ExpressionNode
{
    /// the constant value returned
    double*	value;
    
public:
    /// construct a constant expression node from a value
    explicit ENConstant(double* _value, Assembly& _assembly)
	: ExpressionNode(_assembly), value(_value)
    {
    }

    virtual void evaluate()
    {
        assembly.push(value);
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	    os << indent(depth) << value << std::endl;
    }
};

/** Expression node negating the value of the operand subtree. */
class ENNegate : public ExpressionNode
{
    /// expression subtree
    ExpressionNode* 	node;

public:
    explicit ENNegate(ExpressionNode* _node, Assembly& _assembly)
            : ExpressionNode(_assembly), node(_node)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "- negate" << std::endl;
	node->print(os, depth+1);
    }
};

/** Expression node adding two operand nodes. */
class ENAdd : public ExpressionNode
{
    /// left operand
    ExpressionNode* 	left;

    /// right operand
    ExpressionNode* 	right;
    
public:
    explicit ENAdd(ExpressionNode* _left, ExpressionNode* _right , Assembly& _assembly)
            : ExpressionNode(_assembly), left(_left), right(_right)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "+ add" << std::endl;
	left->print(os, depth+1);
	right->print(os, depth+1);
    }
};

/** Expression node subtracting two operand nodes. */
class ENSubtract : public ExpressionNode
{
    /// left operand
    ExpressionNode* 	left;

    /// right operand
    ExpressionNode* 	right;
    
public:
    explicit ENSubtract(ExpressionNode* _left, ExpressionNode* _right , Assembly& _assembly)
            : ExpressionNode(_assembly), left(_left), right(_right)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "- subtract" << std::endl;
	left->print(os, depth+1);
	right->print(os, depth+1);
    }
};

/** Expression node multiplying two operand nodes. */
class ENMultiply : public ExpressionNode
{
    /// left operand
    ExpressionNode* 	left;

    /// right operand
    ExpressionNode* 	right;
    
public:
    explicit ENMultiply(ExpressionNode* _left, ExpressionNode* _right, Assembly& _assembly)
            : ExpressionNode(_assembly), left(_left), right(_right)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "* multiply" << std::endl;
	left->print(os, depth+1);
	right->print(os, depth+1);
    }
};

/** Expression node dividing two operand nodes. */
class ENDivide : public ExpressionNode
{
    /// left operand
    ExpressionNode* 	left;

    /// right operand
    ExpressionNode* 	right;
    
public:
    explicit ENDivide(ExpressionNode* _left, ExpressionNode* _right , Assembly& _assembly)
            : ExpressionNode(_assembly), left(_left), right(_right)
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
        assembly.compile();
        
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "/ divide" << std::endl;
	left->print(os, depth+1);
	right->print(os, depth+1);
    }
};

/** Expression node calculating the remainder of an integer division of two
 * operand nodes. */
class ENSQRT: public ExpressionNode
{
    /// right operand
    ExpressionNode* 	node;
    
public:
    explicit ENSQRT(ExpressionNode* _node, Assembly& _assembly)
            : ExpressionNode(_assembly), node(_node)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "sqrt" << std::endl;
	node->print(os, depth+1);
    }
};


/** Expression node calculating the remainder of an integer division of two
 * operand nodes. */
class ENIfElseStmt: public ExpressionNode
{
    /// right operand
    ExpressionNode* 	left;
    ExpressionNode* 	right;
    ExpressionNode*     body_if;
    ExpressionNode*     body_else;
    int compareOperator;

public:
    explicit ENIfElseStmt(ExpressionNode* _left, ExpressionNode* _right, int _compareOperator, ExpressionNode* _body_if, ExpressionNode* _body_else, Assembly& _assembly)
    
            : ExpressionNode(_assembly), left(_left), right(_right), compareOperator(_compareOperator), body_if(_body_if), body_else(_body_else)
    {
    }

    virtual ~ENIfElseStmt()
    {
        delete body_if;
        delete body_else;
    }

    virtual void evaluate()
    {
        right->evaluate();
        left->evaluate();
        assembly.operator_= compareOperator;
        assembly.compile();
        body_if->evaluate();
        assembly.jumpForwardTo2();
        assembly.addDynamicLabel1();
        body_else->evaluate();
        assembly.addDynamicLabel2();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
        os << indent(depth) << "if" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
        body_if->print(os, depth+1);
        body_else->print(os, depth+1);
    }
};

/** Expression node raising one operand to the power of the second. */
class ENPower : public ExpressionNode
{
    /// left operand
    ExpressionNode* 	left;

    /// right operand
    ExpressionNode* 	right;
    
public:
    explicit ENPower(ExpressionNode* _left, ExpressionNode* _right, Assembly& _assembly)
            : ExpressionNode(_assembly), left(_left), right(_right)
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
        assembly.compile();
    }

    virtual void print(std::ostream &os, unsigned int depth) const
    {
	os << indent(depth) << "^ power" << std::endl;
	left->print(os, depth+1);
	right->print(os, depth+1);
    }
};

/** ImpalaJIT context used to save the parsed expressions. This context is
 * passed along to the impalajit::Driver class and fill during parsing via bison
 * actions. */
class ExpressionContext {
public:

    /// type of the variable storage
    typedef std::map<std::string, double*> variablemap_type;

    /// variable storage. maps variable string to doubles
    variablemap_type variables;

    /// array of unassigned expressions found by the parser. these are then
    /// outputted to the user.
    std::vector<ExpressionNode *> expressions;

    /// free the saved expression trees
    ~ExpressionContext() {
        clearExpressions();
        clearVariables();
    }

    /// free all saved expression trees
    void clearExpressions() {
        for (unsigned int i = 0; i < expressions.size(); ++i) {
            delete expressions[i];
        }
        expressions.clear();
    }

    /// free all variables
    void clearVariables(){
        variables.clear();
    }

    /// check if the given variable name exists in the storage
    bool existsVariable(const std::string &varname) const {
        return variables.find(varname) != variables.end();
    }

    /// return the given variable from the storage. throws an exception if it
    /// does not exist.
    double* getVariable(const std::string &varname) const {
        variablemap_type::const_iterator vi = variables.find(varname);
        if (vi == variables.end())
            throw (std::runtime_error("Unknown variable."));
        else
            return vi->second;
    }
    Assembly assembly;
};

#endif // EXPRESSION_H
