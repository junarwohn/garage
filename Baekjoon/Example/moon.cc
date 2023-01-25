#define NMEM 5
int main(void) {
    char names[5][10]= { "Amy", "Bob", "Charles", "David", "Liz" }; 
    int DOBs[5] = { 880101, 890101, 910101, 920103, 880102};
    CMember m1("Kim Seon-Suk"); 
    CMember m2("Max", 1, 931208); 
    CMember *memlist =  new CMember[5];
    m1.Print(); 
    // 초기화 또는 맴버 함수를 통해 값이 설정되지 않은 멤버변수는  
    // 그 값이 출력되지 않도록 함.   
    m2.Print(); 
    for (int i = 0; i < NMEM; i++) { 
        (memlist     )->SetName(      )->SetID(      );  
        (memlist     )->SetDOB(      )->Print();   
    }
    // 위에서 괄호 안에 내용을 추가하여 오른쪽과 같이 출력되도록 함.   
    // 각 원소의 이름, 출생일 설정 시 두 배열 names, DOBs를 이용.    
    // 코드 추가 금지.  
    } 
    delete [] memlist; 
}