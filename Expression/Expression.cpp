struct Expression
{
    virtual double evaluate() const = 0;
    
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    
    double evaluate() const { return value; } 

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    
    ~BinaryOperation() {
       delete left;
       delete right;
    }
    
    double evaluate() const {
        double l = left->evaluate();
        double r = right->evaluate();
        switch(op) {
            case '+' :
                return l + r;
            case '*' :
                return l * r;
            case '-' :
                return l - r;
            case '/' :
                 return l / r;
        }
   }
   

private:
    Expression const * left;
    Expression const * right;
    char op;
};