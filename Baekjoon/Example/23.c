#include <stdio.h>

char inputPassword[257], savedPassword[257], checkPassword[257]; //암호 등록, 확인을 위해 암호를 저장할 문자열들; fgets()를 사용할 의도이므로 개행문자를 고려해 총 257개로 저장
int loopQuestion = 0; // 암호조건 루프의 탈출 여부를 위해 선언된 변수

void passwordQuestion() // 비밀번호 조건; 알파벳 대문자만을 입력받기 위한 질문 함수
{
    if(inputPassword[0]=='\n') // 비밀번호를 입력하지 않고 엔터를 입력한 경우 루프 변수값을 1로 바꾸어 재루프 
    {
        printf("Please enter the password.\n");
        loopQuestion = 1;
    }

    if(inputPassword[255]!='\n' && inputPassword[255]!='\0') // 최대값인 255 이상의 입력이 존재하는 경우를 검출해 루프 변수값을 1로 바꾸어 재루프
    {
        printf("Password must be under 255 words.\n");
        for(int i = 0; i <257; i++)
        {
            inputPassword[i] = '\0'; //  다시 입력받기 위해 입력된 암호값 초기화
        }
        while(getchar()!='\n'); // 255자 이상의 입력할 경우 발생할 버퍼 오버플러우를 방지하기 위해 마지막 엔터가 나와 그 다음엔 버퍼가 빌 때까지 getchar()로 문자를 받아오는 방식으로 버퍼를 초기화
        loopQuestion = 1;
    }

    else // 각각의 입력된 원소의 아스키코드 값이 A와 Z의 값 사이에 존재하지 않는 경우를 검출해 재루프
    {
        for(int i = 0; inputPassword[i] != '\n'; i++) 
        {
            if(inputPassword[i]<'A' || inputPassword[i]>'Z') 
            {
                printf("Password must be consisted of only uppercase alphabets.\n");
                for(int i = 0; i <257; i++)
                {
                    inputPassword[i] = '\0';
                }
                loopQuestion = 1;
                break;
            }  
        }
    }
    
    for(int i = 0; i < 257; i++) // fgets()는 입력 문자열 중 '\0'이 아닌 다른 값의 마지막 값 이후에 개행문자 '\n'으로 강제로 변환하므로 그것을 재변환
    {
        if(inputPassword[i] == '\n')
        {
            inputPassword[i] = '\0';
            break;
        }
    }
    
}

void encryption(char* x, char* y) // 알파벳 대문자 하나를 다른 알파벳으로 암호화하는 함수
{
    char result = '\0'; // '\0'은 아스키 코드값이 십진수로 0이므로 덧셈만으로 표현 가능

    if(*x <= 67) // A ~ C의 경우
    {
        result = *x + 23;
    }

    else // D ~ Z의 경우
    {
        result = *x - 3;
    }

    *y = result; // 암호화한 원소를 다른 문자열의 원소로 저장
}

void decryption(char* x, char* y) // 암호화된 알파벳 하나를 원래 알파벳으로 복호화하는 함수
{
    char result = '\0'; // '\0'은 아스키 코드값이 십진수로 0이므로 덧셈만으로 표현 가능

    if(*x >= 88) // A ~ C의 경우
    {
        result = *x - 23;
    }

    else // D ~ Z의 경우
    {
        result = *x + 3;
    }

    *y = result; // 암호화한 원소를 복호화한 값을 다른 문자열의 원소로 저장
}

int comparison(char* x, char* y) // 두 문자열의 원소들을 하나씩 비교해 참, 거짓을 판별해 0,1을 반환하는 함수
{
    int result = *x - *y;
    while (*x && *y) {
        if (*x != *y)
            result = *x - *y;
        x++;y++;
        printf("%c %c\n", *x, *y);
    }
    if (!(*x) && !(*y))
        result = *x - *y;
    printf("comparison result is %d", result);
    return result;
}

int main()
{   
    for(int i = 0; i <257; i++) // 암호를 저장할 문자열들을 처음부터 끝까지 '\0'으로 초기화
    {
        inputPassword[i] = '\0';
        savedPassword[i] = '\0';
        checkPassword[i] = '\0';
    }

    do // 비밀번호 설정을 위해 비밀번호 조건 검정 및 문자열에 저장
    {
        printf("Set your password: ");
        fgets(inputPassword, sizeof(inputPassword), stdin); // 빈칸을 비밀번호로 입력한 것을 검출하기 위해 scanf 대체
        loopQuestion = 0;
        passwordQuestion();
        
    }
    while(loopQuestion == 1);

    printf("Your Password is set: '%s'\n",inputPassword);
    printf("Encrypted password(ACSII code) is: ");

    for(int i = 0; inputPassword[i] != '\0'; i++) // 문자 하나 하나를 암호화할 것이므로 입력된 값이 아닌 '\0' 전까지 암호화하는 것을 반복해서 저장
    {   
        encryption(inputPassword + i, savedPassword + i);
        printf("%c(%d) ", savedPassword[i],(int)savedPassword[i]); // encryption()을 이용해서 암호화된 값을 보여줌
    }
    for(int i = 0; i <257; i++) // 저장된 암호와 재입력될 암호를 비교하기 위해 입력받을 암호를 저장할 문자열을 초기화
    {
        inputPassword[i] = '\0';
    }

    printf("\n");
    printf("Your password is saved.\n");
    printf("******************************\n");
    printf("******************************\n\n");

    do{ // 비밀번호 확인을 위한 루프
        do // 비밀번호 확인을 위해 비밀번호 조건 검정 및 문자열에 저장
        {
            printf("Enter your password: ");
            fgets(inputPassword, sizeof(inputPassword), stdin); // 빈칸을 비밀번호로 입력한 것을 검출하기 위해 scanf 대체
            loopQuestion = 0;
            passwordQuestion();
        }
        while(loopQuestion == 1);
        int len = 0;
        for(int i = 0; inputPassword[i] != '\0'; i++) // 문자 하나 하나를 암호화할 것이므로 입력된 값이 아닌 '\0' 전까지 암호화하는 것을 반복해서 저장
        {   
            encryption(inputPassword + i, checkPassword + i);
            len++;
        }
        *(checkPassword+len) = '\0';
        printf("check password is %s saved password is %s\n", checkPassword, savedPassword);
        if(comparison(checkPassword, savedPassword) == 1) // 입력된 암호가 저장된 암호가 맞을 때까지 질문
        {
            printf("Comparing encrypted string: %s and %s are not same!\n", checkPassword, savedPassword);
            printf("Please enter the right password again!\n");
            for(int i = 0; i <257; i++) // 저장된 암호와 재입력될 암호를 비교하기 위해 입력받을 암호를 임시저장할 문자열과 실제 저장 문자열을 초기화
            {
                inputPassword[i] = '\0';
                savedPassword[i] = '\0';
            }
        }
    }while(comparison(checkPassword, savedPassword) != 0);

    printf("Comparing encrypted strings: %s and %s are same!\n\n", checkPassword, savedPassword);
    printf("Welcome user!!\n\n");

    for(int i = 0; checkPassword[i] != '\0'; i++)
    {
        decryption(inputPassword + i, checkPassword + i); // 입력 암호 문자열과 입력 저장 암호 문자열은 같으므로 한쪽의 원소를 하나씩 복호화해 다른 한쪽에 저장
    }
    printf("Your password is %s\n", savedPassword);

    return 0;
}
