# include "stdio.h"
#ifdef __cplusplus
   extern "C" {
     extern int yyreject();
     extern int yywrap();
     extern int yylook();
     extern void main();
     extern int yyback(int *, int);
     extern int yyinput();
     extern void yyoutput(int);
     extern void yyunput(int);
     extern int yylex();
   }
#endif	/* __cplusplus */
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng;
int yylenguc;
extern unsigned char yytextarr[];
extern unsigned char yytext[];
int yyposix_point=0;
int yynls16=0;
int yynls_wchar=0;
char *yylocale = "/\001:C;\002:C;\003:C;\004:C;:C;:C;:C;/";
int yymorfg;
extern unsigned char *yysptr, yysbuf[];
int yytchar;
FILE *yyin = {stdin}, *yyout = {stdout};
extern int yylineno;
struct yysvf { 
	int yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
/*****************************************************************************/
/**       Copyright 1988 by Evans & Sutherland Computer Corporation,        **/
/**                          Salt Lake City, Utah                           **/
/**  Portions Copyright 1989 by the Massachusetts Institute of Technology   **/
/**                        Cambridge, Massachusetts                         **/
/**                                                                         **/
/**                           All Rights Reserved                           **/
/**                                                                         **/
/**    Permission to use, copy, modify, and distribute this software and    **/
/**    its documentation  for  any  purpose  and  without  fee is hereby    **/
/**    granted, provided that the above copyright notice appear  in  all    **/
/**    copies and that both  that  copyright  notice  and  this  permis-    **/
/**    sion  notice appear in supporting  documentation,  and  that  the    **/
/**    names of Evans & Sutherland and M.I.T. not be used in advertising    **/
/**    in publicity pertaining to distribution of the  software  without    **/
/**    specific, written prior permission.                                  **/
/**                                                                         **/
/**    EVANS & SUTHERLAND AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD    **/
/**    TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  OF  MERCHANT-    **/
/**    ABILITY  AND  FITNESS,  IN  NO  EVENT SHALL EVANS & SUTHERLAND OR    **/
/**    M.I.T. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAM-    **/
/**    AGES OR  ANY DAMAGES WHATSOEVER  RESULTING FROM LOSS OF USE, DATA    **/
/**    OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER    **/
/**    TORTIOUS ACTION, ARISING OUT OF OR IN  CONNECTION  WITH  THE  USE    **/
/**    OR PERFORMANCE OF THIS SOFTWARE.                                     **/
/*****************************************************************************/

/***********************************************************************
 *
 * $XConsortium: lex.l,v 1.62 89/12/10 17:46:33 jim Exp $
 *
 * .twmrc lex file
 *
 * 12-Nov-87 Thomas E. LaStrange		File created
 *
 ***********************************************************************/

/* #include <stdio.h> */		/* lex already includes stdio.h */
#include "gram.h"
#include "parse.h"
extern char *ProgramName;

extern int ParseError;

# define YYNEWLINE 10
yylex(){
   int nstr; extern int yyprevious;
   while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
   if(yywrap()) return(0); break;
case 1:
			{ return (LB); }
break;
case 2:
			{ return (RB); }
break;
case 3:
			{ return (LP); }
break;
case 4:
			{ return (RP); }
break;
case 5:
			{ return (EQUALS); }
break;
case 6:
			{ return (COLON); }
break;
case 7:
			{ return PLUS; }
break;
case 8:
			{ return MINUS; }
break;
case 9:
			{ return OR; }
break;
case 10:
		{ int token = parse_keyword (yytext, 
							     &yylval.num);
				  if (token == ERRORTOKEN) {
				      twmrc_error_prefix();
				      fprintf (stderr,
				       "ignoring unknown keyword:  %s\n", 
					       yytext);
				      ParseError = 1;
				  } else 
				    return token;
				}
break;
case 11:
			{ yylval.num = F_EXEC; return FSKEYWORD; }
break;
case 12:
			{ yylval.num = F_CUT; return FSKEYWORD; }
break;
case 13:
		{ yylval.ptr = (char *)yytext; return STRING; }
break;
case 14:
		{ (void)sscanf(yytext, "%d", &yylval.num);
				  return (NUMBER);
				}
break;
case 15:
		{;}
break;
case 16:
			{;}
break;
case 17:
			{
				  twmrc_error_prefix();
				  fprintf (stderr, 
					   "ignoring character \"%s\"\n",
					   yytext);
				  ParseError = 1;
				}
break;
case -1:
break;
default:
   fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */

static void __yy__unused() { main(); }
yywrap() { return(1);}

#undef unput
#undef input
#undef output
#undef feof
#define unput(c)	twmUnput(c)
#define input()		(*twmInputFunc)()
#define output(c)	TwmOutput(c)
#define feof()		(1)
int yyvstop[] = {
0,

17,
0,

16,
17,
0,

16,
0,

11,
17,
0,

17,
0,

17,
0,

3,
17,
0,

4,
17,
0,

7,
17,
0,

8,
17,
0,

10,
17,
0,

14,
17,
0,

6,
17,
0,

5,
17,
0,

12,
17,
0,

1,
17,
0,

9,
17,
0,

2,
17,
0,

13,
0,

15,
0,

10,
0,

14,
0,

13,
0,
0};
# define YYTYPE unsigned char
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	7,21,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	0,0,	7,21,	
7,21,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	8,24,	0,0,	
0,0,	0,0,	1,6,	1,7,	
1,8,	0,0,	8,24,	8,25,	
7,22,	1,9,	1,10,	2,6,	
1,11,	2,8,	1,12,	1,13,	
23,28,	1,14,	2,9,	2,10,	
7,21,	2,11,	7,21,	2,12,	
0,0,	0,0,	0,0,	1,15,	
0,0,	0,0,	1,16,	8,24,	
0,0,	0,0,	0,0,	0,0,	
2,15,	0,0,	0,0,	2,16,	
0,0,	0,0,	0,0,	8,24,	
0,0,	8,24,	14,27,	14,27,	
14,27,	14,27,	14,27,	14,27,	
14,27,	14,27,	14,27,	14,27,	
0,0,	0,0,	0,0,	0,0,	
0,0,	21,23,	28,23,	1,17,	
0,0,	0,0,	7,23,	0,0,	
0,0,	0,0,	0,0,	0,0,	
2,17,	0,0,	23,23,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	13,26,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,18,	1,19,	1,20,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	2,18,	2,19,	2,20,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	13,26,	13,26,	
13,26,	13,26,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
-1,	0,		0,	
-10,	yysvec+1,	0,	
0,	0,		yyvstop+1,
0,	0,		yyvstop+3,
0,	0,		yyvstop+6,
0,	0,		yyvstop+8,
-6,	0,		yyvstop+11,
-29,	0,		yyvstop+13,
0,	0,		yyvstop+15,
0,	0,		yyvstop+18,
0,	0,		yyvstop+21,
0,	0,		yyvstop+24,
71,	0,		yyvstop+27,
30,	0,		yyvstop+30,
0,	0,		yyvstop+33,
0,	0,		yyvstop+36,
0,	0,		yyvstop+39,
0,	0,		yyvstop+42,
0,	0,		yyvstop+45,
0,	0,		yyvstop+48,
-1,	yysvec+7,	0,	
0,	0,		yyvstop+51,
-14,	yysvec+7,	0,	
0,	yysvec+8,	0,	
0,	0,		yyvstop+53,
0,	yysvec+13,	yyvstop+55,
0,	yysvec+14,	yyvstop+57,
-2,	yysvec+7,	yyvstop+59,
0,	0,	0};
struct yywork *yytop = yycrank+193;
struct yysvf *yybgin = yysvec+1;
unsigned char yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,01  ,'"' ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,'.' ,01  ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,01  ,01  ,01  ,01  ,01  ,
01  ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' ,
'.' ,'.' ,'.' ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
0};
unsigned char yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/* @(#) $Revision: 70.1 $      */
int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
 
#ifdef YYNLS16_WCHAR
unsigned char yytextuc[YYLMAX * sizeof(wchar_t)];
# ifdef YY_PCT_POINT /* for %pointer */
wchar_t yytextarr[YYLMAX];
wchar_t *yytext;
# else               /* %array */
wchar_t yytextarr[1];
wchar_t yytext[YYLMAX];
# endif
#else
unsigned char yytextuc;
# ifdef YY_PCT_POINT /* for %pointer */
unsigned char yytextarr[YYLMAX];
unsigned char *yytext;
# else               /* %array */
unsigned char yytextarr[1];
unsigned char yytext[YYLMAX];
# endif
#endif

struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
unsigned char yysbuf[YYLMAX];
unsigned char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
yylook(){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych, yyfirst;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
/*	char *yylastch;
 * ***** nls8 ***** */
	unsigned char *yylastch, sec;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	yyfirst=1;
	if (!yymorfg)
#ifdef YYNLS16_WCHAR
		yylastch = yytextuc;
#else
		yylastch = yytext;
#endif
	else {
		yymorfg=0;
#ifdef YYNLS16_WCHAR
		yylastch = yytextuc+yylenguc;
#else
		yylastch = yytext+yyleng;
#endif
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = &yycrank[yystate->yystoff];
			if(yyt == yycrank && !yyfirst){  /* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == 0)break;
				}
			*yylastch++ = yych = input();
			yyfirst=0;
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (int)yyt > (int)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((int)yyt < (int)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt = &yycrank[yystate->yystoff]) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
#ifdef YYNLS16_WCHAR
				yylenguc = yylastch-yytextuc+1;
				yytextuc[yylenguc] = 0;
#else
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
#endif
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
#ifdef YYNLS16_WCHAR
					sprint(yytextuc);
#else
					sprint(yytext);
#endif
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
#ifdef YYNLS16_WCHAR
		if (yytextuc[0] == 0  /* && feof(yyin) */)
#else
		if (yytext[0] == 0  /* && feof(yyin) */)
#endif
			{
			yysptr=yysbuf;
			return(0);
			}
#ifdef YYNLS16_WCHAR
		yyprevious = yytextuc[0] = input();
#else
		yyprevious = yytext[0] = input();
#endif
		if (yyprevious>0) {
			output(yyprevious);
#ifdef YYNLS16
                        if (yynls16)
#ifdef YYNLS16_WCHAR
                        	if (FIRSTof2(yytextuc[0]))
#else
                        	if (FIRSTof2(yytext[0]))
#endif
     					if (SECof2(sec = input()))
#ifdef YYNLS16_WCHAR
 						output(yyprevious=yytextuc[0]=sec);
#else
 						output(yyprevious=yytext[0]=sec);
#endif
					else 
						unput(sec);
#endif
                }
#ifdef YYNLS16_WCHAR
		yylastch=yytextuc;
#else
		yylastch=yytext;
#endif
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}

# ifdef __cplusplus
yyback(int *p, int m)
# else
yyback(p, m)
	int *p;
# endif
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(){
	return(input());
	
	}

#ifdef __cplusplus
void yyoutput(int c)
#else
yyoutput(c)
  int c;
# endif
{
	output(c);
}

#ifdef __cplusplus
void yyunput(int c)
#else
yyunput(c)
   int c;
#endif
{
	unput(c);
}
