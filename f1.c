#include "ucode.c"
#include "f2.c"
#include "f3.c"
int color;
goUmode()
{ 
  char name[64]; int pid, cmd, isparent = 0;

  running->inUmode = 1;
    if (isparent == 0) {
        printf("I am the child\n");
    }
 
  while(1){
    pid = getpid();
    color = 0x0C;

      
    printf("----------------------------------------------\n");
    printf("I am proc %d in f1: running segment=%x\n",getpid(), getcs());
    show_menu();
    printf("Command ? ");
    gets(name); 
    if (name[0]==0) 
        continue;

    cmd = find_cmd(name);
    switch(cmd){
           case 0 : getpid();   break;
           case 1 : ps();       break;
           case 2 : chname();   break;
           case 3 : ffork("/bin/f1");
                    isparent = 1;
                    printf("I am the parent\n");
                    break;
           case 4 : kswitch();  break;
           case 5 : wait();     break;
           case 6 : exit();     break;
           case 7 : do_exec();  break;

           default: invalid(name); break;
    }
  }
}


do_exec() {
    char *filename;

    printf("Enter the filename to execute\n");
    filename = gets();
    switch(filename[6]) {
        case '2': goUmode2();   break;
        case '3': goUmode3();   break;
    }
}
