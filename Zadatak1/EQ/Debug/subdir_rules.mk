################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic3204.obj: ../aic3204.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="aic3204.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

aic3204_init.obj: ../aic3204_init.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="aic3204_init.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_aic3204_dma.obj: ../ezdsp5535_aic3204_dma.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_aic3204_dma.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

iir.obj: ../iir.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="iir.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

print_number.obj: ../print_number.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="print_number.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

processing.obj: ../processing.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/home/milan/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/c55xx_csl/inc" --include_path="/media/milan/A6A2677BA2674EBD/Projekti/OAISDSP2/Zadatak1/EQ/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="processing.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


