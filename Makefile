.PHONY : clean main


clean : 
	@echo "Cleaning up"
	@rm -f *.out main
	@echo "Cleaned up"

main : main.cpp
	@echo "Compiling main.cpp"
	g++ -o main main.cpp
	@echo "Running main"
	@./main
	@make clean