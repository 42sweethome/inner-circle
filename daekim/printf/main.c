#include "ft_printf.h"
#include <stdio.h>

int	main()
{
//	int ret;

//	ret = 0;
	ft_printf("[%1.s]\n", 0);
	printf("[%1.s]\n", 0);
	ft_printf("[%1d]\n", 0);
	printf("[%1d]\n", 0);
	ft_printf("[%0.d]\n", 0);
	printf("[%0.d]\n", 0);
	ft_printf("[%.0d]\n", 0);
	printf("[%.0d]\n", 0);
	ft_printf("[%-6.4s]\n", "70000");
	printf("[%-6.4s]\n", "70000");
	ft_printf("[%-2.3s]\n", "12345");
	printf("[%-2.3s]\n", "12345");
	ft_printf("[%-3.6s]\n", "12345");
	printf("[%-3.6s]\n", "12345");
	ft_printf("[%-8.4s]\n", "1234567");
	printf("[%-8.4s]\n", "1234567");
	ft_printf("[%-010.5s]\n", "12345");
	printf("[%-010.5s]\n", "12345");

/*

	printf("\n\n-----------1 option-------------\n\n");
	ft_printf("\n\n-----------1 option-------------\n\n");
	printf("test2[10d]:%10d!\n",123);
	ft_printf("test2[10d]:%10d!\n",123);
	printf("test3[.20]:%.20d!\n",123);
	ft_printf("test3[.20]:%.20d!\n",123);
	printf("test4[-10]:%-10d!\n",123);             
	ft_printf("test4[-10]:%-10d!\n",123);             
	printf("test5[.-20]:%.-20d!\n",123); //negative precisionthe pase 'p'
	ft_printf("test5[.-20]:%.-20d!\n",123); //negative precisionthe pase 'p'
	printf("\n\n------------2 option------------\n\n");
	ft_printf("\n\n------------2 option------------\n\n");
	printf("test6[10.20]:%10.20d!\n",123);
	ft_printf("test6[10.20]:%10.20d!\n",123);
	printf("test7[20.10]:%10.10d!\n",123);
	ft_printf("test7[20.10]:%10.10d!\n",123);
	printf("test8[-10.20]:%-10.20d!\n",123);
	ft_printf("test8[-10.20]:%-10.20d!\n",123);
	printf("test9[10.-20]:%10.-20d!\n",123); //as above
	ft_printf("test9[10.-20]:%10.-20d!\n",123); //as above
	printf("test10[20.-10]:%20.-10d!\n",123);//as above
	ft_printf("test10[20.-10]:%20.-10d!\n",123);//as above
	printf("test11[-20.10]:%-20.10d!\n",123);
	ft_printf("test11[-20.10]:%-20.10d!\n",123);
	printf("\n\n-----------wilddard-------------\n\n");
	ft_printf("\n\n-----------wilddard-------------\n\n");
	printf("test12[10.*(20)]:%10.*d!\n",20,123);
	ft_printf("test12[10.*(20)]:%10.*d!\n",20,123);
	printf("test13[10.*(-20)%10.*d!\n",-20,123);
	ft_printf("test13[10.*(-20)%10.*d!\n",-20,123);
	printf("test14[20.*(10)]:%-10.*d!\n",10,123);
	ft_printf("test14[20.*(10)]:%-10.*d!\n",10,123);
	printf("test15[20.*(-10)]:%-10.*d!\n",-10,123);
	ft_printf("test15[20.*(-10)]:%-10.*d!\n",-10,123);
	printf("test16[*(10).20]:%*.20d!\n",10,123);
	ft_printf("test16[*(10).20]:%*.20d!\n",10,123);
	printf("test17[*(-10).20]:%*.20d!\n",-10,123);
	ft_printf("test17[*(-10).20]:%*.20d!\n",-10,123);
	printf("test18[*(20).10]:%*.10d!\n",20,123);
	ft_printf("test18[*(20).10]:%*.10d!\n",20,123);
	printf("test19[*(-20).10]:%*.10d!\n",-20,123);
	ft_printf("test19[*(-20).10]:%*.10d!\n",-20,123);
	printf("\n\n-------------apply to flag-----------\n\n");
	ft_printf("\n\n-------------apply to flag-----------\n\n");
	printf("test20[-010.20]:%-010.20d!\n",123);//double flag
	ft_printf("test20[-010.20]:%-010.20d!\n",123);//double flag
	printf("test21[-020.10]:%-020.10d!\n",123);//double flag
	ft_printf("test21[-020.10]:%-020.10d!\n",123);//double flag
	printf("test22[010.20]:%010.20d!\n",123);
	ft_printf("test22[010.20]:%010.20d!\n",123);
	printf("test23[010.20]:%020.10d!\n",123);
	ft_printf("test23[010.20]:%020.10d!\n",123);
	printf("\n\n-------------zero-----------\n\n");
	ft_printf("\n\n-------------zero-----------\n\n");
	printf("testz1[0]:%0d!\n",123);
	ft_printf("testz1[0]:%0d!\n",123);
	printf("testz2[0]:%.0d!\n", 123);
	ft_printf("testz2[0]:%.0d!\n", 123);
	printf("test24[0.0]:%0.0d!\n",123);
	ft_printf("test24[0.0]:%0.0d!\n",123);
	printf("test25[10.0]:%10.0d!\n",123);
	ft_printf("test25[10.0]:%10.0d!\n",123);
	printf("test26[0.10]:%0.10d!\n",123);
	ft_printf("test26[0.10]:%0.10d!\n",123);
	printf("\n\n-------------zero in wilddard-----------\n\n");
	ft_printf("\n\n-------------zero in wilddard-----------\n\n");
	printf("test27[*.10]:%*.10d!\n",0, 123);
	ft_printf("test27[*.10]:%*.10d!\n",0, 123);
	printf("test28[*.]:%*.d!\n",0, 123);
	ft_printf("test28[*.]:%*.d!\n",0, 123);
	printf("test29[10.*]:%10.*d!\n",0, 123);
	ft_printf("test29[10.*]:%10.*d!\n",0, 123);
	printf("test30[-10.*]:%-10.*d!\n",0, 123);
	ft_printf("test30[-10.*]:%-10.*d!\n",0, 123);
	printf("test31[*.*]:%*.*d!\n",0,0, 123);
	ft_printf("test31[*.*]:%*.*d!\n",0,0, 123);


	printf("\n\n-----------1 option-------------\n\n");
	ft_printf("\n\n-----------1 option-------------\n\n");
	printf("test1[S]:%s!\n","hahaha");
	ft_printf("test1[S]:%s!\n","hahaha");
	printf("test2[10s]:%10s!\n","hahaha");
	ft_printf("test2[10s]:%10s!\n","hahaha");
	printf("test3[.20]:%.20s!\n","hahaha");
	ft_printf("test3[.20]:%.20s!\n","hahaha");
	printf("test4[-10]:%-10s!\n","hahaha");
	ft_printf("test4[-10]:%-10s!\n","hahaha");
	printf("test5[.-20]:%.-20s!\n","hahaha"); //negative precision == error
	ft_printf("test5[.-20]:%.-20s!\n","hahaha"); //negative precision == error
	printf("\n\n------------2 option------------\n\n");
	ft_printf("\n\n------------2 option------------\n\n");
	printf("test6[10.20]:%10.20s!\n","hahaha");
	ft_printf("test6[10.20]:%10.20s!\n","hahaha");
	printf("test7[20.10]:%10.10s!\n","hahaha");
	ft_printf("test7[20.10]:%10.10s!\n","hahaha");
	printf("test8[-10.20]:%-10.20s!\n","hahaha");
	ft_printf("test8[-10.20]:%-10.20s!\n","hahaha");
	printf("test9[10.-20]:%10.-20s!\n","hahaha"); //negative precision == e
	ft_printf("test9[10.-20]:%10.-20s!\n","hahaha"); //negative precision == error
	printf("test10[20.-10]:%20.-10s!\n","hahaha");//negative precision == error
	ft_printf("test10[20.-10]:%20.-10s!\n","hahaha");//negative precision == e
	printf("test11[-20.10]:%-20.10s!\n","hahaha");
	ft_printf("test11[-20.10]:%-20.10s!\n","hahaha");
	printf("\n\n-----------wildcard-------------\n\n");
	ft_printf("\n\n-----------wildcard-------------\n\n");
	printf("test12[10.*(20)]:%10.*s!\n",20,"hahaha");
	ft_printf("test12[10.*(20)]:%10.*s!\n",20,"hahaha");
	printf("test13[10.*(-20)%10.*s!\n",-20,"hahaha");
	ft_printf("test13[10.*(-20)%10.*s!\n",-20,"hahaha");
	printf("test14[20.*(10)]:%-10.*s!\n",10,"hahaha");
	ft_printf("test14[20.*(10)]:%-10.*s!\n",10,"hahaha");
	printf("test15[20.*(-10)]:%-10.*s!\n",-10,"hahaha");
	ft_printf("test15[20.*(-10)]:%-10.*s!\n",-10,"hahaha");
	printf("test16[*(10).20]:%*.20s!\n",10,"hahaha");
	ft_printf("test16[*(10).20]:%*.20s!\n",10,"hahaha");
	printf("test17[*(-10).20]:%*.20s!\n",-10,"hahaha");
	ft_printf("test17[*(-10).20]:%*.20s!\n",-10,"hahaha");
	printf("test18[*(20).10]:%*.10s!\n",20,"hahaha");
	ft_printf("test18[*(20).10]:%*.10s!\n",20,"hahaha");
	printf("test19[*(-20).10]:%*.10s!\n",-20,"hahaha");
	ft_printf("test19[*(-20).10]:%*.10s!\n",-20,"hahaha");
	printf("\n\n-------------apply flag-----------\n\n");
	ft_printf("\n\n-------------apply flag-----------\n\n");
	printf("test20[-010.20]:%-010.20s!\n","hahaha");//'s' can't use '0'flag
	ft_printf("test20[-010.20]:%-010.20s!\n","hahaha");//'s' can't use '0'flag
	printf("test21[-020.10]:%-020.10s!\n","hahaha");//'-' and '0' can't be 
	ft_printf("test21[-020.10]:%-020.10s!\n","hahaha");//'-' and '0' can't be 
	 
	printf("test22[010.20]:%010.20s!\n","hahaha");//as above '0'
	ft_printf("test22[010.20]:%010.20s!\n","hahaha");//as above '0'
	printf("test23[010.20]:%020.10s!\n","hahaha");//as above '0'
	ft_printf("test23[010.20]:%020.10s!\n","hahaha");//as above '0'
	printf("\n\n-------------zero-----------\n\n");
	ft_printf("\n\n-------------zero-----------\n\n");
	printf("test--[0]:%0s!\n","hahaha");
	ft_printf("test--[0]:%0s!\n","hahaha");
	printf("test24[0.0]:%0.0s!\n","hahaha");
	ft_printf("test24[0.0]:%0.0s!\n","hahaha");
	printf("test25[10.0]:%10.0s!\n","hahaha");
	ft_printf("test25[10.0]:%10.0s!\n","hahaha");
	printf("test26[0.10]:%0.10s!\n","hahaha");
	ft_printf("test26[0.10]:%0.10s!\n","hahaha");
	printf("\n\n-------------zero in wildcard-----------\n\n");
	ft_printf("\n\n-------------zero in wildcard-----------\n\n");
	printf("test27[*.10]:%*.10s!\n",0,"hahaha");
	ft_printf("test27[*.10]:%*.10s!\n",0,"hahaha");
	printf("test28[*.-10]:%*.-10s!\n",0,"hahaha");
	ft_printf("test28[*.-10]:%*.-10s!\n",0,"hahaha");
	printf("test29[10.*]:%10.*s!\n",0,"hahaha");
	ft_printf("test29[10.*]:%10.*s!\n",0,"hahaha");
	printf("test30[-10.*]:%-10.*s!\n",0,"hahaha");
	ft_printf("test30[-10.*]:%-10.*s!\n",0,"hahaha");
	printf("test31[*.*]:%*.*s!\n",0,0,"hahaha");
	ft_printf("test31[*.*]:%*.*s!\n",0,0,"hahaha");

	char a;

	a = 0;
	printf("test1[-16p]:%-16p!\n", 0);
	ft_printf("test1[-16p]:%-16p!\n", 0);
	printf("test2[-16.p]:%-16.p!\n", 0);
	ft_printf("test2[-16.p]:%-16.p!\n", 0);

	printf("test1[p]:%p!\n",&a);
	ft_printf("test1[p]:%p!\n",&a);
	printf("test2[15p]:%15p!\n",&a);
	ft_printf("test2[15p]:%15p!\n",&a);
	printf("test3[.30]:%.30p!\n",&a);//prepision pan't be used in the pase 'p'
	ft_printf("test3[.30]:%.30p!\n",&a);//prepision pan't be used in the pase 'p'
	printf("test4[-15]:%-15p!\n",&a);
	ft_printf("test4[-15]:%-15p!\n",&a);
	printf("test5[.-30]:%.-30p!\n",&a); //as above
	ft_printf("test5[.-30]:%.-30p!\n",&a); //as above
	printf("\n\n------------2 option------------\n\n");
	ft_printf("\n\n------------2 option------------\n\n");
	printf("test6[15.30]:%15.30p!\n",&a);//as above
	ft_printf("test6[15.30]:%15.30p!\n",&a);//as above
	printf("test7[15.15]:%15.15p!\n",&a);//as above
	ft_printf("test7[15.15]:%15.15p!\n",&a);//as above
	printf("test8[-15.30]:%-15.30p!\n",&a);//as above
	ft_printf("test8[-15.30]:%-15.30p!\n",&a);//as above
	printf("test9[15.-30]:%15.-30p!\n",&a); //as above
	ft_printf("test9[15.-30]:%15.-30p!\n",&a); //as above
	printf("test10[30.-15]:%30.-15p!\n",&a);//as above
	ft_printf("test10[30.-15]:%30.-15p!\n",&a);//as above
	printf("test11[-30.15]:%-30.15p!\n",&a);//as above
	ft_printf("test11[-30.15]:%-30.15p!\n",&a);//as above
	printf("\n\n-----------wildpard-------------\n\n");
	ft_printf("\n\n-----------wildpard-------------\n\n");
	printf("test12[15.*(30)]:%15.*p!\n",30,&a);//as above
	ft_printf("test12[15.*(30)]:%15.*p!\n",30,&a);//as above
	printf("test13[15.*(-30)%15.*p!\n",-30,&a);//as above
	ft_printf("test13[15.*(-30)%15.*p!\n",-30,&a);//as above
	printf("test14[-15.*(15)]:%-15.*p!\n",15,&a);//as above
	ft_printf("test14[-15.*(15)]:%-15.*p!\n",15,&a);//as above
	printf("test15[30.*(-15)]:%-15.*p!\n",-15,&a);//as above
	ft_printf("test15[30.*(-15)]:%-15.*p!\n",-15,&a);//as above
	printf("test16[*(15).30]:%*.30p!\n",15,&a);//as above
	ft_printf("test16[*(15).30]:%*.30p!\n",15,&a);//as above
	printf("test17[*(-15).30]:%*.30p!\n",-15,&a);//as above
	ft_printf("test17[*(-15).30]:%*.30p!\n",-15,&a);//as above
	printf("test18[*(30).15]:%*.15p!\n",30,&a);//as above
	ft_printf("test18[*(30).15]:%*.15p!\n",30,&a);//as above
	printf("test19[*(-30).15]:%*.15p!\n",-30,&a);//as above
	ft_printf("test19[*(-30).15]:%*.15p!\n",-30,&a);//as above
	printf("\n\n-------------apply to flag-----------\n\n");
	ft_printf("\n\n-------------apply to flag-----------\n\n");
	printf("test20[-015.30]:%-015.30p!\n",&a);//'p' pan't use '0'flag
	ft_printf("test20[-015.30]:%-015.30p!\n",&a);//'p' pan't use '0'flag
	printf("test21[-030.15]:%-030.15p!\n",&a);//'-' and '0' pan't be used toget
	ft_printf("test21[-030.15]:%-030.15p!\n",&a);//'-' and '0' pan't be used toget
	printf("test22[015.30]:%015.30p!\n",&a);//as above '0'
	ft_printf("test22[015.30]:%015.30p!\n",&a);//as above '0'
	printf("test23[015.30]:%030.15p!\n",&a);//as above '0'
	ft_printf("test23[015.30]:%030.15p!\n",&a);//as above '0'
	printf("\n\n-------------zero-----------\n\n");
	ft_printf("\n\n-------------zero-----------\n\n");
	printf("testz1[0]:%0p!\n",&a);
	ft_printf("testz1[0]:%0p!\n",&a);
	printf("testz2[0]:%.0p!\n", &a);
	ft_printf("testz2[0]:%.0p!\n", &a);
	printf("test24[0.0]:%0.0p!\n",&a);//error "prepision"
	ft_printf("test24[0.0]:%0.0p!\n",&a);//error "prepision"
	printf("test25[15.0]:%15.0p!\n",&a);//error "prepision"
	ft_printf("test25[15.0]:%15.0p!\n",&a);//error "prepision"
	printf("test26[0.15]:%0.15p!\n",&a);//error "prepision"
	ft_printf("test26[0.15]:%0.15p!\n",&a);//error "prepision"
	printf("\n\n-------------zero in wildpard-----------\n\n");
	ft_printf("\n\n-------------zero in wildpard-----------\n\n");
	printf("test27[*.15]:%*.15p!\n",0, &a);//error "prepision"
	ft_printf("test27[*.15]:%*.15p!\n",0, &a);//error "prepision"
	printf("test28[*.]:%*.p!\n",0, &a);
	ft_printf("test28[*.]:%*.p!\n",0, &a);
	printf("test29[15.*]:%15.*p!\n",0, &a);//error "prepision"
	ft_printf("test29[15.*]:%15.*p!\n",0, &a);//error "prepision"
	printf("test30[-15.*]:%-15.*p!\n",0, &a);//error "prepision"
	ft_printf("test30[-15.*]:%-15.*p!\n",0, &a);//error "prepision"
	printf("test31[*.*]:%*.*p!\n",0,0, &a);//error "prepision"
	ft_printf("test31[*.*]:%*.*p!\n",0,0, &a);//error "prepision"


	printf("test1[c]:%c!\n",'a');
	ft_printf("test1[c]:%c!\n",'a');
	printf("test2[10c]:%10c!\n",'a');
	ft_printf("test2[10c]:%10c!\n",'a');
	printf("test3[.20]:%.20c!\n",'a');
	ft_printf("test3[.20]:%.20c!\n",'a');
	printf("test4[-10]:%-10c!\n",'a');
	ft_printf("test4[-10]:%-10c!\n",'a');
	printf("test5[.-20]:%.-20c!\n",'a'); //as above
	ft_printf("test5[.-20]:%.-20c!\n",'a'); //as above
	printf("\n\n------------2 option------------\n\n");
	ft_printf("\n\n------------2 option------------\n\n");
	printf("test6[10.20]:%10.20c!\n",'a');//as above
	ft_printf("test6[10.20]:%10.20c!\n",'a');//as above
	printf("test7[20.10]:%10.10c!\n",'a');//as above
	ft_printf("test7[20.10]:%10.10c!\n",'a');//as above
	printf("test8[-10.20]:%-10.20c!\n",'a');//as above
	ft_printf("test8[-10.20]:%-10.20c!\n",'a');//as above
	printf("test9[10.-20]:%10.-20c!\n",'a'); //as above
	ft_printf("test9[10.-20]:%10.-20c!\n",'a'); //as above
	printf("test10[20.-10]:%20.-10c!\n",'a');//as above
	ft_printf("test10[20.-10]:%20.-10c!\n",'a');//as above
	printf("test11[-20.10]:%-20.10c!\n",'a');//as above
	ft_printf("test11[-20.10]:%-20.10c!\n",'a');//as above
	printf("\n\n-----------wildcard-------------\n\n");
	ft_printf("\n\n-----------wildcard-------------\n\n");
	printf("test12[10.*(20)]:%10.*c!\n",20,'a');//as above
	ft_printf("test12[10.*(20)]:%10.*c!\n",20,'a');//as above
	printf("test13[10.*(-20)%10.*c!\n",-20,'a');//as above
	ft_printf("test13[10.*(-20)%10.*c!\n",-20,'a');//as above
	printf("test14[20.*(10)]:%-10.*c!\n",10,'a');//as above
	ft_printf("test14[20.*(10)]:%-10.*c!\n",10,'a');//as above
	printf("test15[20.*(-10)]:%-10.*c!\n",-10,'a');//as above
	ft_printf("test15[20.*(-10)]:%-10.*c!\n",-10,'a');//as above
	printf("test16[*(10).20]:%*.20c!\n",10,'a');//as above
	ft_printf("test16[*(10).20]:%*.20c!\n",10,'a');//as above
	printf("test17[*(-10).20]:%*.20c!\n",-10,'a');//as above
	ft_printf("test17[*(-10).20]:%*.20c!\n",-10,'a');//as above
	printf("test18[*(20).10]:%*.10c!\n",20,'a');//as above
	ft_printf("test18[*(20).10]:%*.10c!\n",20,'a');//as above
	printf("test19[*(-20).10]:%*.10c!\n",-20,'a');//as above
	ft_printf("test19[*(-20).10]:%*.10c!\n",-20,'a');//as above
	printf("\n\n-------------apply to flag-----------\n\n");
	ft_printf("\n\n-------------apply to flag-----------\n\n");
	printf("test20[-010.20]:%-010.20c!\n",'a');//'c' can't use '0'flag
	ft_printf("test20[-010.20]:%-010.20c!\n",'a');//'c' can't use '0'flag
	printf("test21[-020.10]:%-020.10c!\n",'a');//'-' and '0' can't be used
	ft_printf("test21[-020.10]:%-020.10c!\n",'a');//'-' and '0' can't be used
	printf("test22[010.20]:%010.20c!\n",'a');//as above '0'
	ft_printf("test22[010.20]:%010.20c!\n",'a');//as above '0'
	printf("test23[010.20]:%020.10c!\n",'a');//as above '0'
	ft_printf("test23[010.20]:%020.10c!\n",'a');//as above '0'
	printf("\n\n-------------zero-----------\n\n");
	ft_printf("\n\n-------------zero-----------\n\n");
	printf("testz1[0]:%0c!\n",'a');
	ft_printf("testz1[0]:%0c!\n",'a');
	printf("testz2[0]:%.0c!\n", 'a');
	ft_printf("testz2[0]:%.0c!\n", 'a');
	printf("test24[0.0]:%0.0c!\n",'a');//error "precision"
	ft_printf("test24[0.0]:%0.0c!\n",'a');//error "precision"
	printf("test25[10.0]:%10.0c!\n",'a');//error "precision"
	ft_printf("test25[10.0]:%10.0c!\n",'a');//error "precision"
	printf("test26[0.10]:%0.10c!\n",'a');//error "precision"
	ft_printf("test26[0.10]:%0.10c!\n",'a');//error "precision"
	printf("\n\n-------------zero in wildcard-----------\n\n");
	ft_printf("\n\n-------------zero in wildcard-----------\n\n");
	printf("test27[*.10]:%*.10c!\n",0, 'a');//error "precision"
	ft_printf("test27[*.10]:%*.10c!\n",0, 'a');//error "precision"
	printf("test28[*.-10]:%*.-10c!\n",0, 'a');//error "precision"
	ft_printf("test28[*.-10]:%*.-10c!\n",0, 'a');//error "precision"
	printf("test29[10.*]:%10.*c!\n",0, 'a');//error "precision"
	ft_printf("test29[10.*]:%10.*c!\n",0, 'a');//error "precision"
	printf("test30[-10.*]:%-10.*c!\n",0, 'a');//error "precision"
	ft_printf("test30[-10.*]:%-10.*c!\n",0, 'a');//error "precision"
	printf("test31[*.*]:%*.*c!\n",0,0, 'a');//error "precision"
	ft_printf("test31[*.*]:%*.*c!\n",0,0, 'a');//error "precision"



	printf("\n\n-----------1 option-------------\n\n");
	ft_printf("\n\n-----------1 option-------------\n\n");
	printf("test1[]:%%!\n");
	ft_printf("test1[]:%%!\n");
	printf("test2[10]:%10%!\n");
	ft_printf("test2[10]:%10%!\n");
	printf("test3[.20]:%.20%!\n");
	ft_printf("test3[.20]:%.20%!\n");
	printf("test4[-10]:%-10%!\n");
	ft_printf("test4[-10]:%-10%!\n");
	printf("test5[.-20]:%.-20%!\n"); //negative preci%ion == error  
	ft_printf("test5[.-20]:%.-20%!\n"); //negative preci%ion == error   
	printf("\n\n------------2 option------------\n\n");
	ft_printf("\n\n------------2 option------------\n\n");
	printf("test6[10.20]:%10.20%!\n");
	ft_printf("test6[10.20]:%10.20%!\n");
	printf("test7[20.10]:%10.10%!\n");
	ft_printf("test7[20.10]:%10.10%!\n");
	printf("test8[-10.20]:%-10.20%!\n");
	ft_printf("test8[-10.20]:%-10.20%!\n");
	printf("test9[10.-20]:%10.-20%!\n"); //negative preci%ion == error
	ft_printf("test9[10.-20]:%10.-20%!\n"); //negative preci%ion == error
	printf("test10[20.-10]:%20.-10%!\n");//negative preci%ion == error
	ft_printf("test10[20.-10]:%20.-10%!\n");//negative preci%ion == error
	printf("test11[-20.10]:%-20.10%!\n");
	ft_printf("test11[-20.10]:%-20.10%!\n");
	printf("\n\n-----------wildcard-------------\n\n");                           
	ft_printf("\n\n-----------wildcard-------------\n\n");                           
	printf("test12[10.*(20)]:%10.*%!\n",20);
	ft_printf("test12[10.*(20)]:%10.*%!\n",20);
	printf("test13[10.*(-20)%10.*%!\n",-20);
	ft_printf("test13[10.*(-20)%10.*%!\n",-20);
	printf("test14[20.*(10)]:%-10.*%!\n",10);
	ft_printf("test14[20.*(10)]:%-10.*%!\n",10);
	printf("test15[20.*(-10)]:%-10.*%!\n",-10);
	ft_printf("test15[20.*(-10)]:%-10.*%!\n",-10);
	printf("test16[*(10).20]:%*.20%!\n",10);
	ft_printf("test16[*(10).20]:%*.20%!\n",10);
	printf("test17[*(-10).20]:%*.20%!\n",-10);
	ft_printf("test17[*(-10).20]:%*.20%!\n",-10);
	printf("test18[*(20).10]:%*.10%!\n",20);
	ft_printf("test18[*(20).10]:%*.10%!\n",20);
	printf("test19[*(-20).10]:%*.10%!\n",-20);
	ft_printf("test19[*(-20).10]:%*.10%!\n",-20);
	printf("\n\n-------------apply flag-----------\n\n");
	ft_printf("\n\n-------------apply flag-----------\n\n");
	printf("test20[-010.20]:%-010.20%!\n");
	ft_printf("test20[-010.20]:%-010.20%!\n");
	printf("test21[-020.10]:%-020.10%!\n");
	ft_printf("test21[-020.10]:%-020.10%!\n");
	printf("test22[010.20]:%010.20%!\n");
	ft_printf("test22[010.20]:%010.20%!\n");
	printf("test23[010.20]:%020.10%!\n");
	ft_printf("test23[010.20]:%020.10%!\n");
	printf("\n\n-------------zero-----------\n\n");                 
	ft_printf("\n\n-------------zero-----------\n\n");                 
	printf("test24[0.0]:%0.0%!\n");                 
	ft_printf("test24[0.0]:%0.0%!\n");                 
	printf("test25[10.0]:%10.0%!\n");                 
	ft_printf("test25[10.0]:%10.0%!\n");                 
	printf("test26[0.10]:%0.10%!\n");                 
	ft_printf("test26[0.10]:%0.10%!\n");                 
	printf("\n\n-------------zero in wildcard-----------\n\n");                 
	ft_printf("\n\n-------------zero in wildcard-----------\n\n");                 
	printf("test27[*.10]:%*.10%!\n",0);                 
	ft_printf("test27[*.10]:%*.10%!\n",0);                 
	printf("test28[*.-10]:%*.-10%!\n",0); //error               
	ft_printf("test28[*.-10]:%*.-10%!\n",0); //error               
	printf("test29[10.*]:%10.*%!\n",0);                 
	ft_printf("test29[10.*]:%10.*%!\n",0);                 
	printf("test30[-10.*]:%-10.*%!\n",0);                 
	ft_printf("test30[-10.*]:%-10.*%!\n",0);                 
	printf("test31[-0-0*.*]:%*.*%!\n",0,0);
	ft_printf("test31[-0-0*.*]:%*.*%!\n",0,0);

*/
	return (0);
}
