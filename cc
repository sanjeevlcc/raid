
====================================================

====================================================

https://github.com/prometheus/node_exporter/releases/download/v1.7.0/node_exporter-1.7.0.darwin-amd64.tar.gz

sudo tar xvzf node_exporter-1.2.0.linux-amd64.tar.gz

cd node_exporter-1.2.0.linux-amd64
 cp node_exporter /usr/local/bin

cd /lib/systemd/system
[Unit]
Description=Node Exporter
Wants=network-online.target
After=network-online.target
[Service]
Type=simple
User=node_exporter
Group=node_exporter
ExecStart=/usr/local/bin/node_exporter \
        — collector.mountstats \
        — collector.logind \
        — collector.processes \
        — collector.ntp \
        — collector.systemd \
        — collector.tcpstat \
        — collector.wifi
Restart=always
RestartSec=10s
[Install]
WantedBy=multi-user.target




sudo systemctl daemon-reload
 sudo systemctl enable node_exporter
 sudo systemctl start node_exporter
sudo systemctl status node_exporter

====================================================

====================================================



cd /etc/prometheus
sudo nano prometheus.yml
Now in static_configs in your configuration file replace the target line with the below one

- targets: [‘localhost:9090’, ‘localhost:9100’]
Now restart the Prometheus Service

sudo systemctl restart prometheus
Hit the URL in your web browser to check weather our target is successfully scraped by Prometheus or not

https://localhost:9100/targets


====================================================

====================================================




