//please bisa please

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//calculator.h
class Calculator{
public:
	double evaluate(string problem);					
	double operate(double num1, double num2, char op);	
	double trig(double num1, int n);	
	int precedence(char op);			
};

//queue.h
class Queue {
private:
	int front, rear, size;
	double* array;
public :
    Queue(int size);
    ~Queue();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(double K);
    void characterEnqueue(char C);
    void Dequeue();
    double getFront();
    double getRear();
};

//queue.cpp
Queue::Queue(int size) {
    this->front = 0;
    this->rear = 0;
    this->size = size;
    this->array = new double[size];
    
    if (array == NULL){
    	cout << "Error" << endl;
    	exit(EXIT_FAILURE);
	}
}

//delete the queue
Queue::~Queue() {
    delete[] this->array;
}

//checking if is full
bool Queue::IsFull() {
	//full if size equal to rear
    return (this->size == this->rear);
}

//checking if is empty
bool Queue::IsEmpty(){
	//empty if the front equal to rear
    return (this->front == this->rear);
}

//push the num values
void Queue::Enqueue(double K) {
	
	//check if full
    if (IsFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = K; //put inside the array
        this->rear = this->rear + 1; //increase the rear
    }
    return;
}

//push the char values
void Queue::characterEnqueue(char C) {
	
	//check if full
    if (IsFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = C; //put inside the array
        this->rear = this->rear + 1; //increase the rear
    }
    return;
}

//Queue is First in First out
//But for the purpose of the calculator
//We make the queue to Last in First out
void Queue::Dequeue(){
	
	//check if empty
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
        return;
    }
    
    //dequeue with rear-1
    else {
        this->rear = this->rear - 1;
    }
    return;
}

//getting the front
//never used it
double Queue::getFront(){
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->front];
}

//getting the rear
double Queue::getRear(){
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->rear - 1];
}

//eval

double Calculator::evaluate(string problem){
	int i;
	double pi = 3.141592;		
	Queue values(100);	
	Queue ops(100);	
	
	//Loop to check entire problem
	for (i=0; i < problem.length(); i++){
		
		//ignore the blanks
		if (problem[i] == ' '){
			continue;
		}
		
		//push open bracket to the ops queue
		else if (problem[i] == '('){
			ops.characterEnqueue(problem[i]);
		}
		
		//sin
		else if (problem[i] == 's') {
			int n=1;
			double result = 0;
			//track the number until bracket closed
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
		}
		//cos
		else if (problem[i] == 'c') {
			int n=2;						
			double result = 0;			
			
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1; 
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--)); 
								val = (double) (val) + point;
								i++;
							}
						}
					}
					i--;
					result = trig(val*pi/180, n); 
				}
			}
			values.Enqueue(result);
		}

		//tan
		else if (problem[i] == 't') {
			int n=3;
			double result = 0;
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
		}
		
		//if arc
		else if (problem[i] == 'a') {
			int n;
			double result = 0;
			i++;
			//checking the acos, asin, or atan
			switch(problem[i]){
			    case 's': n=4; break;
				case 'c': n=5; break;
				case 't': n=6; break;
			}
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
		}
		//log or ln
		else if (problem[i] == 'l') {
			int n;
			double result = 0;
			i++;
			switch(problem[i]){
				case 'o': n=7; break;
				case 'n': n=8; break;
			}
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val, n);
				}
			}
			values.Enqueue(result);
		}

		//if input is number
		else if (isdigit(problem[i])){
			double val = 0;
			
			while (i<problem.length() && isdigit(problem[i])){
				val = (val*10) + (problem[i]-'0');
				i++;
				if (problem[i] == '.' || problem[i] == ','){
					i=i+1;
					int j=-1; 
					while (i<problem.length() && isdigit(problem[i])){
						float point = ((problem[i]-'0') * pow(10,j--));
						val = (double) (val) + point; 						
						i++;
					}
				}
			}
			
			values.Enqueue(val); 
			i--; 					//adjust order
		}

		//if square root
		else if (problem[i] == 'r') {
			double result = 0;
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = sqrt(val); //the difference is in the result
				}
			}
			values.Enqueue(result);
		}
		
		//closed bracket, solve inside the bracket
		else if(problem[i] == ')'){
			//see if the ops queue is empty and the ops queue is not the open bracket
			while (!ops.IsEmpty() && ops.getRear() != '('){
				//take first number 
				double val1 = values.getRear();
				values.Dequeue(); 
				
				//take take second number
				double val2 = values.getRear();
				values.Dequeue(); 
				
				//take operator
				char op = ops.getRear();
				ops.Dequeue(); 
				//push result to queue
				values.Enqueue(operate(val1, val2, op)); 
			}
		
			if (!ops.IsEmpty()){
				ops.Dequeue();
			}
		}
		
		//if operator
		else {
			//check if the queue is empty and the precendance
			while (!ops.IsEmpty() && precedence(ops.getRear()) >= precedence(problem[i])){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				//push the result to queue
				values.Enqueue(operate(val1, val2, op)); 
			}
			
			//if the precendance smaller, push the operator to queue
			ops.characterEnqueue(problem[i]);
		}
	}
	
	//after arranging the problem, evaluate
	while(!ops.IsEmpty()){
		double val1 = values.getRear();
		values.Dequeue();
		
		double val2 = values.getRear();
		values.Dequeue();
		
		char op = ops.getRear();
		ops.Dequeue();
		
		values.Enqueue(operate(val1, val2, op));
	}
	
	//final result stored in queue
	return values.getRear();
}

//operation
double Calculator::operate(double num1, double num2, char op){
	switch(op){
		case '+' : return num2 + num1;
		case '-' : return num2 - num1;
		case '*' : return num2 * num1;
		case '/' : return num2 / num1;
		case '^' : return pow(num2, num1);
	}
}

//precedence
int Calculator::precedence(char op){
	if (op == '+' || op == '-'){
		return 1;
	}
	if (op == '*' || op == '/'){
		return 2;
	}
	if (op == '^'){
		return 3;
	}
	else {
		return 0;
	}
}

//trig
double Calculator::trig(double num1, int n){
	switch(n){
		case 1: return sin(num1);
		case 2: return cos(num1);
		case 3: return tan(num1);
		case 4: return asin(num1);
		case 5: return acos(num1);
		case 6: return atan(num1);
		case 7: return log10(num1);
		case 8: return log(num1);
	}
}

//MAIN
int main() {
    Calculator calculator;	
	double history[100] = {0};	
    string problem;			
	double result;		
	int ch = 1;						    
	int key=0;						    
	
	//welcome page
	cout << "======= Scientific Calculator =======\n" << endl;
	cout << "Input requirements: " << endl;
	cout << "1. addition -> a + b\n2. subtraction -> a - b\n3. multiplication -> a * b\n4. division -> a/b\n"
	        "5. trigonometry ->  sin(x), cos(x), tan(x), asin(x), acos(x), atan(x)\n"
	        "6. square root -> r(a)\n7. exponent -> a^b\n8. logarithm -> log(a)\n9. natural log -> ln(a)\n" << endl;
	cout << "Note: -It is possible to input multiple variables\n      -use ( ) for precedence.\n      "
	        "-a and b can be integer or decimal\n      -x is in degrees\n" << endl;
	do {
      cout << "\nClick Enter to Start!";
    } while (cin.get () != '\n');
	
	//program directory
	i:                                      //for looping
	cout << "\nDirectory:" << endl;
	cout << "1 = Calculate a Problem" << endl;
	cout << "2 = Check History" << endl;
    cout << "3 = Clear History" << endl;
    cout << "0 = Exit Calculator" << endl;

	cout << "\nEnter command: ";
	cin >> ch;
	
	while (ch != 0) {
		//calculator
		if (ch == 1) {
			cout << "\nEnter math problem: ";
			cin.ignore();
			getline(cin, problem);
			history[key++] = result = calculator.evaluate(problem);
			cout << "Answer= " << result << endl;
			do {
                cout << "\nEnter to return to directory.";
            } while (cin.get () != '\n');
		}

		//print history
		else if (ch == 2){
			//key as the index
			if(key != 0){
				cout << "\nCalculator History: " << endl;
				for (int i = 0; i < key; i++) {
					cout << "\t" <<  i+1 << ". " << history[i] << endl;
				}
			}
			else {
				cout << "\nNo Calculation History\n";
			}
		}
		
		//clear history
		else if (ch == 3){
		    char c;
			cout << "\nAll history will be deleted and can not be restored, continue?\nEnter 1 for continue and 0 for cancel:" << endl;
			cin >> c;
			//if user wants to continue
			if (c == '1') {
				cout << "\n===History Cleared===" << endl;
				//deleting history contents with loop
				for (int i = 0; i < key; i++){
					history[i] = 0;			
				}
				//reseting the key to 0 so it can be reused 
				key = 0;
			}
			
			//if user wants to cancel
			else {
				continue;
			}
		}
		//if user input invalid command
		else {
			cout << "Invalid Command." << endl;
		}
		//back to directory
		goto i;
	}
	//exit message
	if (ch == 0) {
	        char c;
	        cout << "\n\n!!!Confirm End Program!!!\nEnter 0 to confirm exit and 1 to cancel" << endl;
			cin >> c;
			if (c == '0'){
		        cout << "\n\n\n\n\n\nThank you for using this calculator, Goodbye!" << endl;
			} else goto i;
	}
	return 0;
}
