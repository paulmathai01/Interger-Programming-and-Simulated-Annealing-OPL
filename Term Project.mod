/*********************************************
 * OPL 12.9.0.0 Model
 * Author: paulmathai
 * Creation Date: 13-Dec-2019 at 5:10:57 PM
 *********************************************/
int nPlanes = 100;

range P = 1 ..nPlanes;


//Parameters
int i[P] = ...;
int appt[P] = ...;
int e[P] = ...;
int t[P] = ...;
int l[P] = ...;
float g[P] = ...;
float h[P] = ...;
int s[P][P] = ...;
int uw[P][P] = ...;
int v[P][P] = ...;

//Decision Variables
dvar int x[P];
dvar int alpha[P];
dvar int beta[P];

//Return

dexpr float MinReturn = sum(p in P)((g[p]*alpha[p]) + (h[p]*beta[p]));

minimize
  MinReturn;
 
subject to
{
	const1:
	forall(p in P)
	  e[p]<=x[p]<=l[p];
	const2:
	forall(p in P)
	  forall(p2 in P)
	    s[p][p2] + s[p2][p] == 1;			
	const3:
	forall(p in P)
	  forall(p2 in P)
	    x[p2] >= e[p2] + (x[p] - l[p]);
	const4:
	forall(p in P)
	  alpha[p]>=t[p] - x[p];
	const5:
	forall(p in P)
	  0<=alpha[p]<=t[p] - e[p];
	const6:
	forall(p in P)
	  beta[p]>= x[p] - t[p];
	const7:
	forall(p in P)
	  0 <= beta[p] <= l[p] - t[p];
	const8:
	forall(p in P)
	  x[p] == t[p] - alpha[p] +beta[p];  
	  
}
//Sensitivity Analysis
execute
{
         for (var p in P) writeln( x[p].name," ",x[p].UB," ",x[p].LB);
         for (var p in P) writeln( alpha[p].name," ",alpha[p].UB," ",alpha[p].LB);
         for (var p in P) writeln( beta[p].name," ",beta[p].UB," ",beta[p].LB);
         
}