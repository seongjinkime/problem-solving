![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/s_1928.png)

### 서론
꽤 재미있었던 문제이다. 문자 Decoding 과 Encoding이 어떤 원리로 구현되는지 간접적으로나마 알수 있었던 문제다.

### Type : 구현

#### 접근
1. 문제에 나와있는 Encoding 방식과 Decoding 방식을 간단하게 정리하면 아래와 같다.
```
A. Encoding
 1) 문자 3개를 3Byte(24 bit) Buffer 위에 올린다 
 2) Buffer 위에 올려진 24개의 이진수를 6개 단위로 분할 한다.
 3) 분할된 2진수를 10진수로 변환한 뒤 도표에 나와 있는 문자로 치환한다.
```

```
B. Decoding
 1) 문자열을 4개의 캐릭터 단위로 분할 한다 
 2) 분할된 캐릭터 각각을 도표의 숫자로 치환 한다. 
 3) 4개의 숫자를 24자리 이진수로 변환한다.
 4) 24자리 이진수를 8개 단위로 분할 한다.
 5) 8개자리 이진수를 십진수로 변환 한후 1자리 캐릭터로 변환한다.
```

2. 직관적으로 이해할 수 있도록 예시를 만들어 보았다.
```
A. Encoding
1) L,i,f 
2) 76, 105, 102
3) 0 1 0 0 1 1 | 0 0 0 1 1 0 | 1 0 0 1 0 1 | 1 0 0 1 1 0
4) 19, 6, 37, 38
5) LGlm
```
```
B. Decoding
1) LGlm 
2) 19, 6, 37, 38
3) 0 1 0 0 1 1 0 0 | 0 1 1 0 1 0 0 1 | 0 1 1 0 0 1 1 0
4) 76, 105, 102
5) Lif
```
* 중요 : 테이블에서 최대값 '/'이 63 이하이므로 모든 Decoding input을 6자리 2진수로  변환할 수 있다.

3. 문제에선 Decoding 과정을 요구하므로 Step 별로 필요한 기능을 만들었다
```cpp
1. void build(){}  //Decoding에 참조할 참조표를 만들기 위한 함수
2. vector<int>conv6bit(int num) //Decoding 할 숫자를 6bit로 변환시켜 주는 함수
3. int conv2num(vector<int>bits) //8비트 이진수를 10진수로 변환시켜 주는 함수
```

3. 총 3개의 함수를 순차적으로 호출하면서 Decoding을 호출한다
```cpp
void decode(vector<char> chars){
    vector<int>bits;

    int nums[4];
    
    for(int i = 0 ; i < 4 ; i++){
        char ch = chars[i];
        nums[i] = codes[ch];
    }
    
    for(int i = 0 ; i < 4 ; i++){
        int num = nums[i];
        vector<int> bit = conv6bit(num);
        for(int i = 0 ; i < 6 ; i++){
            bits.push_back(bit[i]);
        }
    }
    
    for(int i = 0 ; i < 24 ; i+=8){
        vector<int> bit = vector<int>{bits.begin()+i, bits.begin()+(i+8)};
        cout<<(char)conv2num(bit);
    }
    
}
```

4.  문자열 전체를 4개씩 나누어 Decoding 진행
```cpp
void solve(int t, string s){
    cout<<"#"<<t<<" ";
    for(int i = 0 ; i < s.size() ; i+=4){
           vector<char> target = vector<char>{s.begin() + i, s.begin()+(i+4) };
           decode(target);
    }
    cout<<endl;
}
```

5. 함수별 코드
이외로 2진수 변환이 헷갈려서 고충을 많이 겪었다. 다음엔 헷갈리지 않도록 이 기회에 되새기려 한다.  

(1) 10진수를 6자리 2진수로 변환
```cpp
vector<int>conv6bit(int num){
    vector<int>bit = vector<int>(6, 0); //6자리 vector 선언
    int position = 0;                   //배열의 위치를 나타낼 position
    while(num>0){                       //num이 0이 아닐 동안
        bit[position++] = num%2;        //num 을 2로 나눈 나머지를 저장 한다 
        num/=2;                         //num을 2로 나눈다
    }
    reverse(bit.begin(), bit.end());    //숫자를 뒤에서 부터 나누었으므로 앞뒤를 뒤집어 준다 
    return bit;
}
```

(2) 8자리 2진수를 10진수로 변환
```cpp
int conv2num(vector<int>bits){
    int pw = pow(2, 7);             //2의 8승
    int sum = 0;                    //0으로 초기화
    
    for(int i = 0 ; i < 8 ; i++){
        sum += bits[i] * pw;        //1 * pw or 0 * pw
        pw /= 2;                    //2를 나누어 승을 낮춤
    }
    
    return sum;                     //합계 반환
}
```

6. 느낀점
1) 처음엔 문제를 이해하느라 생각보다 많은 시간이 걸렸다.
2) 2진수의 자릿수 (8자리 혹은 6자리) 문제로 인해 헷갈림이 있었다
3) 참조 테이블을 만드는데도 쉽지 않았다
4) 하나씩 구현해나가다 보니 완성을 할 수 있었다 (3시간 가량 소요)
5) 오랜만에 긴 시간의 구현과 성취감을 느낄 수 있었던 문제다.
