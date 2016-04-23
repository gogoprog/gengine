STRING(
    var gengineApp;

    function __preinit()
    {
        gengineApp = Module.gengineApp;

        Main.init();

        gengineApp.setup();
        gengineApp.start();
    }

    __preinit();
);
