int main() {
	char m[] = "ABC";
	char* ap = m;
	*ap++ += 1;		
	*++ap += 3;		
	ap -= 2;		
	ap[1] += 2;		
	puts(m);		
}