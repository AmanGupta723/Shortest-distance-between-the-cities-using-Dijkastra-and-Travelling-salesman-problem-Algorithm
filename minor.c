#include<stdio.h>
#include <limits.h>
#define V 28
void mincost(int city);
void takeInput();
int dijkstra(int graph[V][V],int dest1);
int minDistance(int dist[],int sptSet[]);
int intermediate(int graph[V][V],int dest1);	
int printSolution(int dist[]);
int a[10],s;
 int least(int c);
int ary[10][10],completed[10],n,cost=0;
int num[13];
int tsp_arry[13],z=0,sum;
char capital[30][30]={"Agartala","Aizawl","Bengaluru","Bhopal","Bhubaneswar","Chandigarh","Chennai","Dehradun","Dispur",
"Gandhinagar","Gangtok","Hyderabad_Amaravati","Hyderabad_shared_with_Ap","Imphal","Itanagar","Jaipur","Kohima","Kolkata","Lucknow",
"Mumbai","Panaji","Patna","Raipur","Ranchi","Shillong","Shimla","Srinagar","Thiruvananthapuram"};
int src,dest;// SOURCE AND DESTINATION

int dist[30][30] = {
   {0    ,349  ,3433 ,2752 ,1983 ,2720 ,3220 ,2670 ,544  ,3156 ,1087 ,2969 ,2933 ,545  ,833  ,2497 ,680  ,1576 ,1923 ,3298 ,3742 ,1475 ,2209 ,1650 ,457  ,2818 ,3285 ,3989},
   {349  ,0    ,3361 ,2510 ,1910 ,2647 ,3148 ,2598 ,462  ,3084 ,1014 ,2514 ,2860 ,400  ,675  ,2424 ,543  ,1502 ,1851 ,3225 ,3669 ,1403 ,2164 ,1578 ,384  ,2746 ,3212 ,3905},
   {3433 ,3361 ,0    ,1442 ,1445 ,2413 ,347  ,2363 ,2888 ,1515 ,2523 ,663  ,569  ,3364 ,3123 ,2044 ,3231 ,1185 ,1876 ,984  ,602  ,2110 ,1373 ,1962 ,2973 ,2512 ,2978 ,723 },
   {2752 ,2510 ,1442 ,0    ,1182 ,1032 ,1474 ,982  ,2035 ,609  ,1671 ,1120 ,850  ,2511 ,2271 ,594  ,2379 ,1420 ,647  ,775  ,1219 ,1035 ,631  ,1023 ,2121 ,1131 ,1597 ,2173},
   {1983 ,1910 ,1445 ,1182 ,0    ,1879 ,1241 ,1829 ,1443 ,1685 ,1079 ,819  ,1062 ,1919 ,1679 ,1656 ,1787 ,443  ,1136 ,1639 ,1713 ,767  ,549  ,453  ,1528 ,1977 ,2444 ,2002},
   {2720 ,2647 ,2413 ,1032 ,1879 ,0    ,2460 ,205  ,2189 ,1139 ,1825 ,2105 ,1836 ,2665 ,2424 ,517  ,2533 ,1742 ,806  ,1677 ,2105 ,1336 ,1491 ,1491 ,2274 ,113  ,564  ,3158},  
   {3220 ,3148 ,347  ,1474 ,1241 ,2460 ,0    ,2396 ,2674 ,1868 ,2309 ,447  ,627 ,3150  ,2909 ,2076 ,3017 ,1671 ,1908 ,1337 ,935  ,1908 ,1173 ,1616 ,2759 ,2544 ,3010 ,773},
   {2670 ,2598 ,2363 ,982  ,1829 ,205  ,2396 ,0    ,1942 ,1192 ,1778 ,2059 ,1789 ,2418 ,2177 ,542  ,2285 ,1695 ,580  ,1654 ,2098 ,1290 ,1445 ,1444 ,2027 ,228  ,758  ,3111},
   {544  ,462  ,2888 ,2035 ,1443 ,2189 ,2674 ,1942 ,0    ,2620 ,551  ,2274 ,2397 ,482  ,323  ,1960 ,462  ,1149 ,1387 ,2762 ,3206 ,939  ,167  ,1114 ,91   ,2282 ,2749 ,3441},
   {3156 ,3084 ,1515 ,609  ,1685 ,1139 ,1868 ,1192 ,2620 ,0    ,2256 ,1522 ,1240 ,3097 ,2856 ,662  ,2964 ,2063 ,1236 ,545  ,1103 ,1768 ,1137 ,1726 ,2706 ,1261 ,1625 ,2253},
   {1087 ,1014 ,2523 ,1671 ,1079 ,1825 ,2309 ,1778 ,551  ,2256 ,0    ,1905 ,2029 ,1020 ,782  ,1593 ,888  ,671  ,1019 ,2394 ,2838 ,571  ,1331 ,745  ,646  ,1914 ,2381 ,3077},
   {2962 ,2514 ,663  ,1120 ,819  ,2105 ,447  ,2059 ,2274 ,1522 ,1905 ,0    ,840  ,2739 ,2498 ,1721 ,2606 ,1260 ,1592 ,993  ,927  ,1494 ,521  ,1201 ,2348 ,2189 ,2656 ,1216},
   {2933 ,2860 ,569  ,850  ,1062 ,1836 ,627  ,1789 ,2397 ,1240 ,2029 ,840  ,0    ,2887 ,2646 ,1452 ,2754 ,1493 ,1324 ,711  ,656  ,1519 ,779  ,1371 ,2496 ,1920 ,2387 ,1306},
   {545  ,400  ,3364 ,2511 ,1919 ,2665 ,3150 ,2418 ,482  ,3097 ,1020 ,2739 ,2887 ,0    ,457  ,2434 ,136  ,1513 ,1861 ,3235 ,3679 ,1412 ,2146 ,1588 ,475  ,2756 ,3222 ,3916},
   {833  ,675  ,3123 ,2271 ,1679 ,2424 ,2909 ,2177 ,323  ,2856 ,782  ,2498 ,2646 ,457  ,0    ,2195 ,320  ,1273 ,1622 ,2997 ,3440 ,1174 ,1948 ,1349 ,381  ,2525 ,2992 ,3678},
   {2497 ,2424 ,2044 ,594  ,1656 ,517  ,2076 ,542  ,1960 ,662  ,1593 ,1721 ,1452 ,2434 ,2195 ,0    ,2302 ,1511 ,574  ,1148 ,1604 ,1108 ,1200 ,1261 ,2044 ,606  ,1072 ,2754},
   {680  ,543  ,3231 ,2379 ,1787 ,2533 ,3017 ,2285 ,462  ,2964 ,888  ,2606 ,2754 ,136  ,320  ,2302 ,0    ,1381 ,1728 ,3103 ,3546 ,1280 ,2025 ,1455 ,415  ,2631 ,3098 ,3782},
   {1576 ,1502 ,1185 ,1420 ,443  ,1742 ,1671 ,1695 ,1149 ,2063 ,671  ,1260 ,1493 ,1513 ,1273 ,1511 ,1381 ,0    ,975  ,2032 ,2192 ,583  ,939  ,414  ,1123 ,1267 ,2334 ,2442},
   {1923 ,1851 ,1876 ,647  ,1136 ,806  ,1908 ,580  ,1387 ,1236 ,1019 ,1592 ,1324 ,1861 ,1622 ,574  ,1728 ,975  ,0    ,1375 ,1818 ,533  ,807  ,741  ,1471 ,905  ,1372 ,2737},
   {3298 ,3225 ,984  ,775  ,1639 ,1677 ,1337 ,1654 ,2762 ,545  ,2394 ,993  ,711  ,3235 ,2997 ,1148 ,3103 ,2032 ,1375 ,0    ,571  ,1756 ,1091 ,1694 ,2852 ,1757 ,2173 ,1722},
   {3742 ,3669 ,602  ,1219 ,1713 ,2105 ,935  ,2098 ,3206 ,1103 ,2838 ,927  ,656  ,3679 ,3440 ,1604 ,3546 ,2192 ,1818 ,571  ,0    ,2139 ,1429 ,2018 ,3297 ,2204 ,2725 ,983},
   {1475 ,1403 ,2110 ,1035 ,767  ,1336 ,1908 ,1290 ,939  ,1768 ,571  ,1494 ,1519 ,1412 ,1174 ,1108 ,1280 ,583  ,533  ,1756 ,2139 ,0    ,745  ,397  ,1022 ,1443 ,1910 ,2818},
   {2209 ,2164 ,1373 ,639  ,549  ,1491 ,1173 ,1445 ,167  ,1137 ,1331 ,521  ,779  ,2146 ,1948 ,1200 ,2025 ,939  ,807  ,1091 ,1429 ,745  ,0    ,588  ,1787 ,1581 ,2047 ,1937},
   {1650 ,1578 ,1962 ,1023 ,453  ,1491 ,1616 ,1444 ,1114 ,1726 ,745  ,1201 ,1371 ,1588 ,1349 ,1261 ,1455 ,414  ,741  ,1694 ,2018 ,397  ,588  ,0    ,1190 ,1612 ,2078 ,2380},
   {457  ,384  ,2973 ,2121 ,1528 ,2274 ,2759 ,2027 ,91   ,2706 ,646  ,2348 ,2496 ,475  ,381  ,2044 ,415  ,1123 ,1471 ,2852 ,3297 ,1022 ,1787 ,1190 ,0    ,2375 ,2842 ,3526},
   {2818 ,2746 ,2512 ,1131 ,1977 ,113  ,2544 ,228  ,2282 ,1261 ,1914 ,2189 ,1920 ,2756 ,2525 ,606  ,2631 ,1267 ,905  ,1757 ,2204 ,1443 ,1581 ,1612 ,2375 ,0    ,633  ,3256},
   {3285 ,3212 ,2978 ,1597 ,2444 ,564  ,3010 ,758  ,2749 ,1625 ,2381 ,2656 ,2387 ,3222 ,2992 ,1072 ,3098 ,2334 ,1372 ,2173 ,2725 ,1910 ,2047 ,2078 ,2842 ,633  ,0    ,3723},
   {3989 ,3905 ,723  ,2173 ,2002 ,3158 ,773  ,3111 ,3441 ,2253 ,3077 ,1261 ,1306 ,3916 ,3678 ,2754 ,3728 ,2442 ,2737 ,1722 ,983  ,2818 ,1937 ,2380 ,3526 ,3256 ,3723 ,0}
};



	int graph[V][V] ={ 
					{0   ,349 ,0   ,0   ,0   ,0   ,0   ,0   ,544 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {349 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,462 ,0   ,0   ,0   ,0   ,400 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,347 ,0   ,0   ,0   ,0   ,663 ,569 ,0   ,0   ,0   ,0   ,0   ,0   ,984 ,602 ,0   ,0   ,0   ,0   ,0   ,0   ,723},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,609 ,0   ,0   ,0   ,0   ,0   ,594 ,0   ,0   ,647 ,775 ,0   ,0   ,639 ,1023,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,819 ,0   ,0   ,0   ,0   ,0   ,443 ,0   ,0   ,0   ,0   ,549 ,453 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,205 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,517 ,0   ,0   ,806 ,0   ,0   ,0   ,0   ,0   ,0   ,112 ,562 ,0},
                    {0   ,0   ,347 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,447 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,773},
                    {0   ,0   ,0   ,0   ,0   ,205 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,580 ,0   ,0   ,0   ,0   ,0   ,0   ,228 ,0   ,0},
                    {544 ,462 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,482 ,323 ,0   ,462 ,1149,0   ,0   ,0   ,0   ,0   ,0   ,91  ,0   ,0   ,0},
                    {0   ,0   ,0   ,609 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,662 ,0   ,0   ,0   ,545 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,671 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,663 ,0   ,819 ,0   ,447 ,0   ,0   ,0   ,0   ,0   ,840 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,521 ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,569 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,840 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,711 ,0   ,0   ,779 ,0   ,0   ,0   ,0   ,0},
                    {0   ,400 ,0   ,0   ,0   ,0   ,0   ,0   ,482 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,136 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,323 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,320 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,594 ,0   ,517 ,0   ,0   ,0   ,662 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,574 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,462 ,0   ,0   ,0   ,0   ,136 ,320 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,443 ,0   ,0   ,0   ,1149,0   ,671 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,583 ,0   ,414 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,647 ,0   ,806 ,0   ,580 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,574 ,0   ,0   ,0   ,0   ,0   ,533 ,807 ,741 ,0   ,0   ,0   ,0},
                    {0   ,0   ,984 ,775 ,0   ,0   ,0   ,0   ,0   ,545 ,0   ,0   ,711 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,571 ,0   ,1091,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,602 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,571 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,583 ,533 ,0   ,0   ,0   ,0   ,397 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,639 ,549 ,0   ,0   ,0   ,0   ,0   ,0   ,521 ,779 ,0   ,0   ,0   ,0   ,0   ,807 ,1091,0   ,0   ,0   ,588 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,1023,453 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,414 ,741 ,0   ,0   ,397 ,588 ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,91  ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,112 ,0   ,228 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,633 ,0},
                    {0   ,0   ,0   ,0   ,0   ,562 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,633 ,0   ,0},
                    {0   ,0   ,723 ,0   ,0   ,0   ,773 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0}
					};
int main()
	{
		int option,count=0,i=0;
		char c, user_name;
		int password;
		
		 	printf("username: ");
		 	scanf("%s",&user_name);
		 	printf("\nPassword: ");
		 	scanf("%d",&password);
			if(password!=12345)			 
			{
			  printf("\nyour password is incorrect\n");
			  printf("\nEnter the correct password: ");
			  scanf("%d",&password);
			  
			}
		 if (password==12345)
		 
		 {		
			option=Display_first_page();
			while(count==0)
				{
					scanf("%d",&option);	
						switch (option)
							{	
	
	    						case 1:
							    	if (option==1)
							        src_dest();
							    	count++;
							    	break; 
								case 2:
							    	if (option==2)							    		
 										takeInput();
										printf("<--------------------Follow the below route to reach the destination----------------------->\n\n\n");
										mincost(0); //passing 0 because starting vertex
												printf("\n\nMinimum Distance to visit the cities is %d KM\n  ",cost);
											
							    		count++;
							     		break;
							    case 3:
							    	//while(i<20)
							    	{
									if (option==3)
									 printf("\n\n\n--------------Comparision between the Dijkastra algorithm and Travel Sales person--------------\n\n\n");
									 	takeInput();
										printf("\n<--------------------Follow the below route to reach the destination----------------------->\n");
										mincost(0); //passing 0 because starting vertex
												printf("\n\n\n\nResult shown by TSP ( Using Dynamic approach)\n");
												printf("----------------------------------------------\n");
												printf("\nMinimum Distance calculted by TSP (Dynamic Approach) = %d KM\n \n\n\n\n\n",cost);
												comparision();
							    		count++;
							    	
									break;
							   // i++;
									}
									//comparsion();
								default:
							   	{
							     	printf("\t\t\t----------------------------\n");
								 	printf("\t\t\t|                          |\n");-
								 	printf("\t\t\t|Oops! somethimg went WRONG|\n");
								 	printf("\t\t\t|                          |\n");
								 	printf("\t\t\t----------------------------\n");
							   		printf("\n\nPlease Select the Right option:\n");
							   		
								}
							}
				}
	}	

}


int Display_first_page()
	{
		printf("\n-------------------------------------------------Travel Portal ----------------------------------------------------\n");
		printf("\n\n\t\t\t\t\t Select the option to visit the city\n");
		printf("\n\n\n1.  if you only want to visit the destination\n");
		printf("2.  if you want to come back to the source point via visiting some intermediate city");
		printf("\n3.  To compare the Dijkastra algorithm and Travel Sales person (by Dynamic algorithm)");
		
		printf("\n\n\n Enter the option.\n");
		
	}

int src_dest()
	{
		int i;
	
			printf("<------------List of city------------>\n");
			for(i=0;i<V;i++)
				{
		    		printf(" %d. %s\n",i+1,capital[i]);
				}
			printf("\n<----------------Select your city from the above list-------------------->\n");
			printf("\n\n\nEnter your source NUMBER\n");
			scanf("%d",&src);
			while(src>28)
				{
				
			     	printf("\t\t\t----------------------------\n");
				 	printf("\t\t\t|                          |\n");
				 	printf("\t\t\t|Oops! somethimg went WRONG|\n");
				 	printf("\t\t\t|                          |\n");
				 	printf("\t\t\t----------------------------\n");
			   		printf("\n\nPlease Select the Right option:\n");
		   			scanf("%d",&src);
				}
			printf("\nEnter your Destination NUMBER\n");
			scanf("%d",&dest);
			while (dest>28)
				{	
			     	printf("\t\t\t----------------------------\n");
				 	printf("\t\t\t|                          |\n");
				 	printf("\t\t\t|Oops! somethimg went WRONG|\n");
				 	printf("\t\t\t|                          |\n");
				 	printf("\t\t\t----------------------------\n");
			   		printf("\n\nPlease Select the Right option:\n");
					scanf("%d",&dest);
				}
			printf("\nSource        =   %s\nDestination   =   %s\n",capital[src-1],capital[dest-1]);
			src=src-1;
			dest=dest-1;
			dijkastra(graph,dest,src);
			printf("\n\n\n<--------------------Follow the below route to reach the destination----------------------->\n");
			intermediate(graph,dest);
				printf("\n\n\n");
			printf("\n%s----------->",capital[src]);
			sequnce();
			printf("%s",capital[dest]);
				printf("\n\n\n");
			return 0;
	}
		
//------------------dijkastra_ algorithm----------------
int dijkastra (int graph[V][V],int dest,int src)
	{
		int i,count,v;
	    int dist[V];
	    int sptSet[V];
		int dest_in;
			for (i = 0; i < V; i++)
	    	{
	        	dist[i] = INT_MAX;
				sptSet[i] = 0;
	     	}
	    	dist[src] = 0;	
	    	for ( count = 0; count < V-1; count++)
		    	{
		       		int u = minDistance(dist, sptSet);
		       			sptSet[u] = 1;
		       			for (v = 0; v < V; v++)
		        		{
							if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
		        				{
									dist[v] = dist[u] + graph[u][v];
						
		     					}
						}
				}	
		   printf("\nDistance From %s to %s = %dKM  ",capital[src],capital[dest], dist[dest]); 
		return dist[dest];
		}
		
	
		
int minDistance(int dist[],int sptSet[])
	{
	   	int min = INT_MAX, min_index,v;
	   		for ( v = 0;v < V;v++)
	     		{
			 		if (sptSet[v] == 0 && dist[v] <= min)
	         			min = dist[v], min_index = v;
	        	}
	   	return min_index;
	}
	
		//---------------intermediate city---------------
int intermediate(int graph[V][V],int dest1)
	{
		int i,count,v;
	    int dist[V];
	    int sptSet[V];
		int dest_in;
			for (i = 0; i < V; i++)
	    		{
	        		dist[i] = INT_MAX;
					sptSet[i] = 0;
	     		}
		    dist[src] = 0;	    
		    for ( count = 0; count < V-1; count++)
		    	{
		       		int u = minDistance(dist, sptSet);
		       		sptSet[u] = 1;
		       			for (v = 0; v < V; v++)
		        		{
							if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
		        				{
									dist[v] = dist[u] + graph[u][v];
		        					if(v==dest1)
		        						{							
		        							dest_in=u;
		        								if(capital[src]!=capital[dest_in])
		        		        					{ 	        
		        	        							a[s]=dest_in;
		        	        							s++;
		        	        						}
		        	       				}
		     					}	
						}
						 
				}	
			if(src!=dest_in)
	 			intermediate( graph, dest_in);
 
	}
int sequnce()          // to print the path 
	{
		int i,j,t,r=0;


			for(j=0;j<s;j++)
				for(i=j+1;i<s;i++)
					{
						if(a[j]==a[i])
        					{  
								for(t=j;t<s;1<t++)
									a[t]=a[t+1];
    							s=s-1;
							}
					}
									
			for(i=s-1;i>=0;i--)
				printf("%s-------------->",capital[a[i]]);
		return 0;
	}
	
 
 void takeInput()

{	int i, j;
	
		printf("<------------List of city------------>\n");
		for(i=0;i<V;i++)
			{
			    printf(" %d. %s\n",i+1,capital[i]);
			}	
		printf("\n--------------------------------------------------------------------------------------------");
		printf("\n\nSelect source City from the above cities\n");
		printf("\nEnter the numbers of intermediates cities-> ");
		scanf("%d", &n);
		n=n+1;
		for(i=0; i<n; i++)
			{
			 	if (i==0)
					{
						printf("Enter the source number:");
						
			 			scanf("%d",&num[i]);
			 			if(num[i]>28)
			 				{						 
			 					printf("\t\t\t----------------------------\n");
								printf("\t\t\t|                          |\n");
								printf("\t\t\t|Oops! somethimg went WRONG|\n");
								printf("\t\t\t|                          |\n");
								printf("\t\t\t----------------------------\n");
							   	printf("\n\nPlease Select the Right option:\n");
							   	scanf("%d", &num[i]);
							}
					}
			 	else
				 	{
					 	printf("\nEnter the intermediate city number-> ",i+1);
						scanf("%d", &num[i]);
						if(num[i]>28)
			 				{						 
					 			printf("\t\t\t----------------------------\n");
								printf("\t\t\t|                          |\n");
								printf("\t\t\t|Oops! somethimg went WRONG|\n");
								printf("\t\t\t|                          |\n");
								printf("\t\t\t----------------------------\n");
								printf("\n\nPlease Select the Right option:\n");
								scanf("%d", &num[i]);
							}
						
					}
			}
		
		for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					ary[i][j] = dist[num[i]-1][num[j]-1];
				}
				printf("\n");
			}	  
}

void mincost(int city)
	{
		int i,ncity;
			completed[city]=1;
			tsp_arry[z]=num[city]-1; // tsp_ arry is used to compare the algos;
			z++;
			printf("%s--------->",capital[num[city]-1]);
			ncity=least(city);	 
			if(ncity==99999)
				{
					ncity=0;
					printf("%s",capital[num[ncity]-1]);
					cost+=ary[city][ncity];
				return;
				}
			mincost(ncity);
	}	

 	
int least(int c)
	{
		int i,nc=99999;
		int min=99999,kmin;
	 
			for(i=0;i < n;i++)
				{
					if((ary[c][i]!=0)&&(completed[i]==0))
						if(ary[c][i]+ary[i][c] < min)
							{
								min=ary[i][0]+ary[c][i];
								kmin=ary[c][i];
								nc=i;
							}
				}	 
			if(min!=99999)
				cost+=kmin;	 
		return nc;
	}
int comparision()
	{
		int i=0;
			printf("\n\nResult shown by the Dijkastra Algorithm\n");
			printf("----------------------------------------------\n\n");
			for(i=0;i<z-1;i++)
				{
					if(i-1!=z)
		    			sum+=dijkastra(graph,tsp_arry[i+1],tsp_arry[i]);    	
				}
			sum+=dijkastra(graph,tsp_arry[0],tsp_arry[z-1]);
			printf("\n\nTotal distance  calculted by dijkastra = %d KM",sum);	
			if (cost< sum)
			{
				printf("\n\nIN this case, TSP is better \n\n");
				printf("Difference in distance to cover the path by TSP and Dijkastra = %d\n\n\n" ,sum-cost);
				sum=0;
			}
			else
				printf("\n\nIN this case,  Dijkastra Algoritm is better \n\n\n\n");
				sum=0;
			
	}
