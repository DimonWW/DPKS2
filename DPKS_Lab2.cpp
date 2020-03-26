#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag;

void version(){
  puts ("Argument: Version\n");
}

void help(){
  puts ("Argument: Help\n");
}

void value(char* val){
  printf ("Argument: Value with value '%s'\n", val);
}

void list(char* lst){
  if (lst!=NULL){ 
    printf ("Argument: List with list of values '%s'\n", lst);
  }
  else {
    printf ("Argument: List\n");
  }
}

int
main (int argc, char **argv)
{
  int c;
  bool l = true;
  bool v = true;
  bool h = true;
  bool V = true;

  while (1)
    {
      static struct option long_options[] =
        {
          {"list", optional_argument, 0, 'l'}, {"version", no_argument, 0, 'v'},
          {"help", no_argument, 0, 'h'}, {"value", required_argument, 0, 'V'},
          {"list", optional_argument, 0, 'L'}, {0, 0, 0, 0}
        };

      int option_index = 0;

      c = getopt_long (argc, argv, "l::vhV:L::",
                       long_options, &option_index);

      if (c == -1)
        break;

      switch (c)
        {
        case 0:

          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with argument %s", optarg);
          printf ("\n");
          break;

        case 'l':
          if (l){
            list(optarg);
            l=!l;
          }
          break;

        case 'v':
          if (v){
            version();
            v=!v;
          }
          break;

        case 'h':
          if (h){
            help();
            h=!h;
          }
          break;

        case 'V':
          if (V){
            value(optarg);
            V=!V;
          }
          break;

        case 'L':
          if (l){
            list(optarg);
            l=!l;
          }
          break;

        case '?':

          break;

        default:
          abort ();
        }
    }

  if (optind < argc)
  {
    exit(1);
  }

  exit (0);
}
