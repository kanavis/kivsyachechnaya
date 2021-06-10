if (!Date.now) {
    Date.now = function() { return new Date().getTime(); }
}

$(() => {
    console.log('Window init');

    let refresh_time = 0;
    let e_display_refresh_time = $('#display-refresh-time');
    let e_display_temp = $('#display-temp');
    let e_display_hum = $('#display-hum');
    let e_display_err = $('#display-error');


    function update_refresh_time() {
        if (!refresh_time) return;

        let refresh_ago = Math.floor((Date.now() - refresh_time) / 1000);
        let refresh_time_str;

        if (refresh_ago < 60) {
            refresh_time_str = refresh_ago + ' sec ago';
        } else if (refresh_ago < 3600) {
            refresh_time_str = Math.floor(refresh_ago / 60) + ' min ago';
        } else {
            refresh_time_str = ' > ' + Math.floor(refresh_ago / 3600) + ' h ago';
        }

        e_display_refresh_time.html(refresh_time_str);
    }


    function update_temp_hum() {
        console.log('Sensors update start');

        $.ajax('/api/1/sensors/get_all/', {
            'method': 'GET',
            'dataType': 'json',
            'headers': {'Accept': 'text/json'},
            'success': (data) => {
                console.log('Sensors update end', data);
                
                refresh_time = Date.now();
                e_display_temp.html(data.dht1.temperature ?? '??');
                e_display_hum.html(data.dht1.humidity ?? '??');
                e_display_err.html('');
                update_refresh_time();
                if (data.dht1.temperature === null || data.dht1.humidity === null) {
                    setTimeout(update_temp_hum, 10 * 1000);
                } else {
                    setTimeout(update_temp_hum, 10 * 60 * 1000);
                }
            },
            'error': (jqXHR, textStatus, errorThrown) => {
                console.log('Sensors update error', jqXHR, textStatus, errorThrown);

                refresh_time = 0;
                e_display_err.html('Error: ' + textStatus + ' ' + errorThrown);
                e_display_temp.html('??');
                e_display_hum.html('??');

                setTimeout(update_temp_hum, 10 * 1000);
            },
        });
    }

    update_temp_hum();
    setInterval(update_refresh_time, 10 * 1000);

});
