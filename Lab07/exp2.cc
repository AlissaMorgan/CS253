int main() {    
	char *x = new char[11];//[10]
	x[10] = 'a';
	delete[] x; //added
	return 0;
}
