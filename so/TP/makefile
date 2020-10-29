CC = gcc
DISTDIR = dist
OBJDIR = dist/objdir
SRCDIR = src
# FLAGS=-D DEBUG

# ECHO CORES
E_RED = '\033[0;31m'
E_YELLOW = '\033[1;33'
E_LBLUE = '\033[1;34m'
E_GREEN = '\033[0;32m'
E_RESET = '\033[0m'
# Mais cores em: 
#	https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux

# ECHO [MENSAGENS] COLORIDAS
E_RED_ERRO = '[\033[0;31mERRO\033[0m] '
E_YELLOW_AVISO = '[\033[1;33mAVISO\033[0m] '
E_LBLUE_INFO = '[\033[1;34mINFO\033[0m] '

# CHEATSHEET - Compilador
	# $<   Variável automática "Target"
	# $@   Variável automática "Source"
	# $*   Variável inserida no nome da regra, indicada por *
# CHEATSHEET - Makefile
	# $(VAR)		Usar variável "VAR"
	# @   			Esconde o comando de aparecer no terminal
	# .PHONY: ###   Impede que ### seja identificado como ficheiro por defeito pelo makefile

# Compila todos os targets
all: cliente arbitro

# Compila o cliente
cliente: cliente.o
	$(CC) $(OBJDIR)/$@.o -o $(DISTDIR)/cliente
	@echo $(E_LBLUE_INFO)"Executável do cliente criado."

cliente.o: $(SRCDIR)/cliente/* directorias
	$(CC) -c $(FLAGS) $< -o $(OBJDIR)/$@
	@echo $(E_LBLUE_INFO)"Objeto do cliente criado."

# Compila o árbitro
arbitro: arbitro.o
	$(CC) $(OBJDIR)/$@.o -o $(DISTDIR)/arbitro
	@echo $(E_LBLUE_INFO)"Executável do árbitro criado."

arbitro.o: $(SRCDIR)/arbitro/* directorias
	$(CC) -c $(FLAGS) $< -o $(OBJDIR)/$@
	@echo $(E_LBLUE_INFO)"Objeto do árbitro criado."

# Compila o jogo
jogo-%: jogo-%.o
	$(CC) $(OBJDIR)/$@.o -o $(DISTDIR)/g_$*
	@echo $(E_LBLUE_INFO)"Executável do jogo "$(E_GREEN)$*$(E_RESET)" criado."

jogo-%.o: $(SRCDIR)/jogos/%.c directorias
	$(CC) -c $(FLAGS) $< -o $(OBJDIR)/$@
	@echo $(E_LBLUE_INFO)"Objeto do jogo "$(E_GREEN)$*$(E_RESET)" criado."
	
# Cria diretorias de compilação
directorias:
# Directoria de distribuição 
	@mkdir -p $(DISTDIR)
	@mkdir -p $(OBJDIR)
	@echo $(E_LBLUE_INFO)"Diretorias /"$(DISTDIR)" e /"$(OBJDIR)" criadas."

# Eliminar ficheiros de apoio à compilação e executáveis
.PHONY : clean all
clean: # Comandos suprimidos de echo (não aparecem no terminal)
# Apagar ficheiros de apoio
	@rm -f $(OBJDIR)/*.o
# Apagar executáveis
	@rm -f $(DISTDIR)/arbitro $(DISTDIR)/cliente $(DISTDIR)/g_*
# Apagar pasta objetos
	@rm -rf $(OBJDIR)