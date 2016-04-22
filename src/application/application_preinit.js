STRING(
    var gengineApp;

    function __preinit()
    {
        gengineApp = Module.gengineApp;

        Main.init();

        gengineApp.setMustLoadGui(true);
    }

    __preinit();
);
