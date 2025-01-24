import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

//빠른 속도 - 대량으로 입력 받을 때 scanner 말고 버퍼리더를 이용해서 입력을 받음 

public class Swea_2072 {

public static void main(String[] args) throws IOException { //예외처리 //입출력에 있어서 문제가 생기면 main의 상위인 jvm으로 넘겨 프로그램을 종료시킴.
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    //한줄을 통째로 문자열로 읽을 수 있는 객체를 생성 

    int T = Integer.parseInt(br.readLine());
    int sum;
    
    for(int j=0; j<T; j++) {
    	sum =0;
    	String line = br.readLine(); //3 17 1 39 8 41 2 32 99 2 이 입력을 띄어쓰기 포함 하나의 문자열로 저장
    	String[] tokens = line.split(" "); //띄어쓰기로 구분하여 하나씩 문자열로 저장 
    	for(String token : tokens) {
    		int num = Integer.parseInt(token); //문자열을 정수형으로 형변환 
    		if(num%2 != 0) {
    			sum += num;
    		}
    	}
        
        bw.write("#"+(j+1)+" "+sum+"\n");
        
    }
    
    bw.flush(); //쌓여 있는 버퍼를 즉시 비우는 메서드. 스트림은 유지. 
    			// close 메소드 내부에서 flush가 이루어지지만 버퍼안에 남아있다가 출력되지 않는 일을 예방하기 위해서 반복문이나 로직 끝에 flush() 해주는게 좋음 
    bw.close(); //내부 버퍼를 모두 flush한 후 스트림을 종료. //반드시 필요한 메서드.
    br.close(); //java 내부에서 종료해주지만 명시적으로 해주는게 좋다.
}
}