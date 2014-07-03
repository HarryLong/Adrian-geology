<?php
require 'HomePage.inc';
require 'PageCreator.inc';

$page_creator = new PageCreator("page_data/HomePage.xml");
$page_data = $page_creator->parse();

$homepage = new HomePage($page_data);
$homepage->display();
?>