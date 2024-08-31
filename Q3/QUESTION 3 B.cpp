#include <iostream>

int gcd(int x, int y) {
    while (y !=0){
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
int reduce(int&num, int&denom) {
    if (num <= 0 || denom <= 0) {
        return 0;
    }
    
    int gcd_value=gcd(num,denom);
    
    num /= gcd_value;
    denom /= gcd_value;
    return 1;
    
    
}

int main(){
	int num =7;
	int denom =2;
	if (reduce(num, denom)){
	std::cout<<"reduced fraction"<<num<<"/"<<denom<< std::endl;	
		
		
	}
	else {
	std::cout<<"failed to reduce the fraction"<<std::endl;	
		
		
	}
	return 0;
	
}






