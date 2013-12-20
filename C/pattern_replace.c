#include "pattern_replace.h"

//helper functions
static char *sstrndup(const char *str, size_t slen)
{
	char *new;
	if( (new = malloc(slen+1)) == NULL )
	{
		fprintf(stderr,"%s malloc failed at %d in %s\n",
				__func__, __LINE__,__FILE__);
		return NULL;
	}
	memcpy(new, str, slen);
	new[slen]='\0';
	return new;
}

char *pattern_replace(const char *str, 
    const char *pattern, const char*replace)
{
	size_t slen, plen, rlen, nlen;
	size_t occurrences;
	size_t i, j;
	char *new;

	//check if we really have a string to work on
	if(str == NULL)
		return NULL; 

	slen = strlen(str);
	if(0 == slen)
		return NULL; 
	
	//no pattern or no possible match
	if(pattern == NULL)
		plen = 0;
	else
		plen = strlen(pattern);

	if(0 == plen || plen > slen )
		return new = sstrndup(str, slen);
	
	//check if there is something to replace pattern with
	if(replace == NULL)
		rlen = 0;
	else
		rlen = strlen(replace);

	if(0 == rlen)
		return new = sstrndup(str,slen);
	
	//find the number of occurrences
	occurrences = 0;
	for(char *p=(char*)str; *p!='\0'; )
	{
		if(strncmp(pattern,p,plen) == 0)
		{
			p+=plen;
			occurrences++;
			continue;
		}
		p++;
	}
	
	//calculate new str length
	nlen = (rlen - plen) * occurrences + slen + 1;
	
	if( (new = malloc(nlen)) == NULL )
	{
		fprintf(stderr,"%s malloc failed at %d in %s\n",
				__func__, __LINE__, __FILE__);
		return NULL;
	}

	
	i = j = 0;
	//copy until hit '\0'
	while( (new[i] = str[j]) )
	{
		//check if pattern
		if(strncmp(pattern, &str[j], plen) == 0)
		{
			//replace it in new string
			memcpy(&new[i], replace, rlen);
			i+=rlen; 
			j+=plen;
			continue;
		}
		//next
		i++;
		j++;
	}

	return new;
	
}
