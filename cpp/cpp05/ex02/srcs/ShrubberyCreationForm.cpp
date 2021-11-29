#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Form", 145, 137, "warrr_Mansion")
{
    std::cout << "Create ShrubberyCreationForm!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src)
{
    std::cout << "Create Copy ShrubberyCreationForm!" << std::endl;
    *this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("Shrubbery Form", 145, 137, target)
{
    std::cout << "Create ShrubberyCreationForm!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        ;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Delete ShrubberyCreationForm!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::fstream file;
    std::string shrubbery;

    if (getSign() == false)
        throw NotSignedException;
    if (executor.getGrade() > getExecuteGrade())
        throw *GradeTooLowException;
    try
	{
		file.open(getTarget() + "_shrubbery", std::ios::out);
		if (file.fail())
			throw file.fail();
	}
	catch (int error)
	{
		std::cout << "Error : open" << std::endl;
		exit(0) ;
	}
    std::cout << "ShrubberyForm : Plant a tree at <" << getTarget() << "> " << std::endl;
    for (int i = 0; i < 25; i++)
        file << GetShrubbery(i) << std::endl;
    file.close();
}

std::string ShrubberyCreationForm::GetShrubbery(int idx) const
{
    std::string shrubbery[25];
    shrubbery[0] = "           *             ,";
    shrubbery[1] = "                       _/^\\_";
    shrubbery[2] = "                      <     >";
    shrubbery[3] = "     *                 /.-.\\         *";
    shrubbery[4] = "              *        `/&\\`                   *";
    shrubbery[5] = "                      ,@.*;@,";
    shrubbery[6] = "                     /_o.I %_\\    *";
    shrubbery[7] = "        *           (`'--:o(_@;";
    shrubbery[8] = "                   /`;--.,__ `')             *";
    shrubbery[9] =  "                  ;@`o % O,*`'`&\\";
    shrubbery[10] =  "            *    (`'--)_@ ;o %'()\\      *";
    shrubbery[11] =  "                 /`;--._`''--._O'@;";
    shrubbery[12] =  "                /&*,()~o`;-.,_ `''`)";
    shrubbery[13] =  "     *          /`,@ ;+& () o*`;-';\\";
    shrubbery[14] =  "               (`''--.,_0 +% @' &()\\";
    shrubbery[15] =  "               /-.,_    ``''--....-'`)  *";
    shrubbery[16] =  "          *    /@%;o`:;'--,.__   __.'\\";
    shrubbery[17] =  "              ;*,&(); @ % &^;~`'`o;@();         *";
    shrubbery[18] =  "              /(); o^~; & ().o@*&`;&%O\\";
    shrubbery[19] =  "              `'='==''==,,,.,='=='==='`";
    shrubbery[20] =  "           __.----.(\\-''#####---...___...-----._";
    shrubbery[21] =  "         '`         \\)_`'''''`";
    shrubbery[22] =  "                 .--' ')";
    shrubbery[23] =  "               o(  )_-\\";
    shrubbery[24] =  "                 `'''` `";
    return (shrubbery[idx]);
}
