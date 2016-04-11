STRING(

    application = application || {};
    var gengine = new Module.App();

    if(typeof application.init !== 'undefined')
    {
        application.init();
    }

    gengine.setup();
    gengine.start();

    if(typeof application.start !== 'undefined')
    {
        application.start();
    }

    while(1)
    {
        gengine.runFrame();
        application.update(gengine.getTimeStep());
    }

);
