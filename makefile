project_manager: main.c project_manager.o project_manager_amin.o
	gcc main.c project_manager.o project_manager_amin.o -o project_manager
project_manager.o: project_manager.c
	gcc -c project_manager.c
project_manager_amin.o: project_manager_amin.c
	gcc -c project_manager_amin.c
clean:
	rm *.o project_manager