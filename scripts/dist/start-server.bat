set GENGINE_DISTRIBUTED=1
set GENGINE=%~dp0

cd %GENGINE%
python scripts/gengine-run %1
