
/* Exercise 1 */

when(275,10).
when(261,12).
when(381,11).
when(398,12).
when(399,12).

where(275,owen102).
where(261,dear118).
where(381,cov216).
where(398,dear118).
where(399,cov216).

enroll(mary,275).
enroll(john,275).
enroll(mary,261).
enroll(john,381).
enroll(jim,399).


schedule(X,P,T) :- enroll(X,C), where(C,P), when(C,T).

usage(P,T) :- where(C,P), when(C,T).

conflict(C,D) :- where(C,P), where(D,P), when(C,T), when(D,T), C<D.

meet(X,Y) :- enroll(X,C), enroll(Y,C), X\=Y.
meet(X,Y) :- enroll(X,C), enroll(Y,D),
             where(C,P), where(D,P),
             when(C,T1), when(D,T2),
             T2 is T1+1, X\=Y.

meetSym(X,Y) :- meet(X,Y); meet(Y,X).



/* Exercise 2 */

rdup([X,X|Xs],Ys)   :- rdup([X|Xs],Ys), !.
rdup([X|Xs],[X|Ys]) :- rdup(Xs,Ys).
rdup([],[]).

/* alternatives:

rdup([X,X|Xs],Ys)     :- rdup([X|Xs],Ys), !.
rdup([X,Y|Xs],[X|Ys]) :- X\=Y, rdup([Y|Xs],Ys), !.
rdup(Xs,Xs).

no cut needed:

rdup([X,X|Xs],Ys)     :- rdup([X|Xs],Ys).
rdup([X,Y|Xs],[X|Ys]) :- X\=Y, rdup([Y|Xs],Ys).
rdup([X],[X]).
rdup([],[]).

*/


flat([],[]).
flat([X|L],F) :- flat(X,FX), flat(L,FL), append(FX,FL,F).
flat(X,[X]).


project(Ns,Xs,Ys) :- project(0,Ns,Xs,Ys).

project(_,[],_,[]).
project(_,_,[],[]).
project(M,[N|Ns],[X|Xs],[X|Ys]) :- N =:= M+1, project(N,Ns,Xs,Ys).
project(M,[N|Ns],[_|Xs],Ys)     :- K is M+1, project(K,[N|Ns],Xs,Ys).
