#include <iostream>
#include <string>
using namespace std;

class Stack{
    int capacity;
    char* arr;
    int top;
    public:
    Stack(int size){
        this->capacity = size;
        this->top = -1;
        this->arr= new char[capacity];
    }
    
    bool isfull(){
        return top == capacity-1;
    }
    
    bool isempty(){
        return top == -1;
    }
    
    void push(char ch){
        if(!isfull())
        arr[top++]=ch;
    }
    void pop(){
        if(!isempty())
        top--;
    }

    char peek(){
        return arr[top];
    } 
    
};

int prec(char ch){
    if(ch=="^") return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-') return 1;
    else
    return -1;
}

void infixtopostfix(char* arr,int n){
    Stack st(n);
    string res;
    for(int i=0;i<n;i++){
        if(arr[i]==')')
        st.push(arr[i]);

        else if((arr[i]>='A' && arr[i]<='Z') || (arr[i]>='a' && arr[i]<='z'))
        res+=arr[i];

        else if(arr[i]==')'){
            while(st.peek()!='(' || !st.isempty()){
                st.pop();
            }
        }

        else{
            while(!st.isempty()  &&  prec(arr[i])<=prec(st.peek())){
                res+=st.peek();
                st.pop();
            }
            st.push(arr[i]);
        }

    }
    while(!st.isempty()){
        res+=st.peek();
        st.pop();
    }
    cout<<res;
}


int main() {
    char arr[]={'a','+','b','+','c'};
    int n=sizeof(arr)/sizeof(char);
    return 0;
}
