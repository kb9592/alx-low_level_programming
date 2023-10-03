#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_anthr(Elf64_Ehdr headerfile);

/**
 * print_magic - prints magic bytes of the ELF file
 * @headerfile: the pointer for the ELF file
 */
void print_magic(Elf64_Ehdr headerfile)
{
	int k;

	printf(" Magic: ");
	for (k = 0; k < EI_NIDENT; k++)
		printf("%2.2x%s", headerfile.e_ident[k], k == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - prints the ELF class header
 * @headerfile: it points to the ELF class array
 */
void print_class(Elf64_Ehdr headerfile)
{
	printf(" Class: ");
	switch (headerfile.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none");
			break;

		case ELFCLASS32:
			printf("ELF32");
			break;

		case ELFCLASS64:
			printf("ELF64");
			break;
	}
	printf("\n");
}

/**
 * print_data - prints the data of ELF
 * @headerfile: the pointer of the ELF class array
 */

void print_data(Elf64_Ehdr headerfile)
{
	printf(" Data ");
	switch (headerfile.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's compliment, big endian");
		break;
		case ELFDATA2LSB:
			printf("2's compliment, little endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
	}
	printf("\n");
}


/**
 * print_version - this prints ELF header
 * *@headerfile: pointer to ELF array
 */
void print_version(Elf64_Ehdr headerfile)
{
	printf(" Version: %d", headerfile.e_ident[EI_VERSION]);
	switch (headerfile.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
		break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * print_osabi - this prints OSABI of an ELF header
 * @headerfile: points to array of ELF version
 */

void print_osabi(Elf64_Ehdr headerfile)
{
	printf(" OS/ABI: ");
	switch (headerfile.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_anthr(headerfile);
			break;
	}
	printf("\n");
}

/**
 * print_anthr -this prints in addition
 * @headerfile: the header of the program
 */
void print_anthr(Elf64_Ehdr headerfile)
{
	switch (headerfile.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone APP");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", headerfile.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - prints ABI version of ELF
 * @headerfile: array of ELF version
 */
void print_abiversion(Elf64_Ehdr headerfile)
{
	printf(" ABI Version: %d\n",
			headerfile.e_ident[EI_ABIVERSION]);
}

/**
 * print_type -this prints ELF header type
 * @headerfile: the array
 */
void print_type(Elf64_Ehdr headerfile)
{
	char *pr = (char *)&headerfile.e_type;
	int k = 0;

	printf(" Type: ");
	if (headerfile.e_ident[EI_DATA] == ELFDATA2MSB)
		k = 1;
	switch (pr[k])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown: %x>", pr[k]);
			break;
	}
	printf("\n");
}

/**
 * print_entry - prints entry point
 * @headerfile: pointer for ELF class array
 */
void print_entry(Elf64_Ehdr headerfile)
{
	int k = 0;
	int range = 0;
	unsigned char *pr = (unsigned char *)&headerfile.e_entry;

	printf("The address entry point: 0x");
	if (headerfile.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		k = headerfile.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!pr[k])
			k--;
		printf("%x", pr[k--]);
		for (; k >= 0; k--)
			printf("%02x", pr[k]);
		printf("\n");
	}
	else
	{
		k = 0;
		range = headerfile.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!pr[k])
			k++;
		printf("%x", pr[k++]);
		for (; k <= range; k++)
			printf("%02x", pr[k]);
		printf("\n");
	}
}

/**
 * main - gives details in the ELF header
 *  of the ELF file
 *  @argc: the number of arguments given to the program
 *  @argv: array of pointers
 *  Return: 1 if successful, 0 if fails
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr headerfile;
	int i;
	ssize_t j;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	i = open(argv[1], O_RDONLY);
	if (i == -1)
		dprintf(STDERR_FILENO, "Can't open from the file: %s\n", argv[1]), exit(98);
	j = read(i, &headerfile, sizeof(headerfile));
	if (j < 1 || j != sizeof(headerfile))
		dprintf(STDERR_FILENO, "Cannot read from file: %s\n", argv[1]), exit(98);
	if (headerfile.e_ident[0] == 0x7f && headerfile.e_ident[1] == 'E' &&
			headerfile.e_ident[2] == 'L' && headerfile.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "File does not exist: %s\n", argv[1]), exit(98);

	print_magic(headerfile);
	print_class(headerfile);
	print_data(headerfile);
	print_version(headerfile);
	print_osabi(headerfile);
	print_abiversion(headerfile);
	print_type(headerfile);
	print_entry(headerfile);
	if (close(i))
		dprintf(STDERR_FILENO, "Error when closing the file: %d\n", i), exit(98);
	return (EXIT_SUCCESS);
}
