package JniTest;

public class JniTest {
	private native void PrintHelloWorld(); 
		
	static {
		System.loadLibrary("JniTest");
	}
		
	public static void main(String[] args) {
		JniTest jni = new JniTest();
		jni.PrintHelloWorld();
	}
}
