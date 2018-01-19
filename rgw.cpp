CEPH_LIBCEPHD_API int cephd_run_rgw(int argc, const char **argv);
	int cephd_run_rgw(int argc, const char **argv)
		extern "C" int cephd_rgw(int argc, const char **argv)
			int RGWCivetWebFrontend::run()
				cb.begin_request = civetweb_callback;
				ctx = mg_start(&cb, this, options.data()); --civetweb API
				static int civetweb_callback(struct mg_connection* conn)
					return static_cast<RGWCivetWebFrontend *>(req_info->user_data)->process(conn);
					int RGWCivetWebFrontend::process(struct mg_connection*  const conn)
						int ret = process_request(env.store, env.rest, &req, env.uri_prefix,
						int process_request(RGWRados* const store,

op = handler->get_op(store);
	RGWOp* RGWHandler_REST::get_op(RGWRados* store)







RGWHandler_REST *handler = rest->get_handler(store, s,
	RGWRESTMgr *m = mgr.get_manager(s, frontend_prefix, s->decoded_uri,
                                  &s->relative_uri);
		return get_resource_mgr(s, frontend_prefix + uri, out_uri);


	RGWHandler_REST* handler = m->get_handler(s, auth_registry, frontend_prefix);
	RGWHandler_REST* RGWRESTMgr_S3::get_handler(struct req_state* const s,
		RGWHandler_REST_S3::init_from_header(s,





rgw::auth::StrategyRegistry::s3_main_strategy_t s3_main_strategy
	add_engine(Strategy::Control::SUFFICIENT, s3_main_strategy_plain);
	add_engine(Strategy::Control::FALLBACK, s3_main_strategy_boto2);


rgw::auth::Strategy::apply(const rgw::auth::Strategy& auth_strategy,
	auto result = auth_strategy.authenticate(s);
		engine_result = engine.authenticate(s);
		AWSEngine::authenticate(const req_state* const s) const
			const auto auth_data = ver_abstractor.get_auth_data(s);
			AWSGeneralAbstractor::get_auth_data(const req_state* const s) const
				return get_auth_data_v4(s, route == AwsRoute::QUERY_STRING);
				AWSGeneralAbstractor::get_auth_data_v4(const req_state* const s,
					int ret = rgw::auth::s3::parse_credentials(s->info,
						ret = parse_v4_auth_header(info, credential, signedheaders,
		return authenticate(auth_data.access_key_id,
		rgw::auth::s3::LocalEngine::authenticate(
			if (rgw_get_user_info_by_access_key(store, access_key_id, user_info) < 0) {
				return rgw_get_user_info_from_index(store, access_key,
					int rgw_get_system_obj(RGWRados *rgwstore, RGWObjectCtx& obj_ctx, const rgw_pool& pool, const string& key, bufferlist& bl,
						int ret = rop.stat(objv_tracker);
							return store->stat_system_obj(source->get_ctx(), state, obj, stat_params.attrs, ##commit
								int r = get_system_obj_state(&obj_ctx, obj, &astate, objv_tracker);
									ret = get_system_obj_state_impl(rctx, obj, state, objv_tracker);
										RGWRawObjState *s = rctx->raw.get_state(obj);
										int r = raw_obj_stat(obj, &s->size, &s->mtime, &s->epoch, &s->attrset, (s->prefetch_data ? &s->data : NULL), objv_tracker);
										int RGWCache<T>::raw_obj_stat(rgw_raw_obj& obj, uint64_t *psize, real_time *pmtime,
											r = T::raw_obj_stat(obj, &size, &mtime, &epoch, &info.xattrs, first_chunk, objv_tracker);
												int r = get_raw_obj_ref(obj, &ref);
													r = open_pool_ctx(ref->pool, ref->ioctx);
														int r = rgw_init_ioctx(rad, pool, io_ctx);
															int r = rados->ioctx_create(pool.name.c_str(), ioctx);
																int ret = rados_ioctx_create((rados_t)client, name, &p);
																	int r = client->create_ioctx(name, &ctx);

int RGWRados::open_pool_ctx(const rgw_pool& pool, librados::IoCtx&  io_ctx)


CEPH_LIBCEPHD_API int cephd_run_mon(int argc, const char **argv);
int cephd_run_mon(int argc, const char **argv)
	return cephd_mon(argc, argv);
	extern "C" int cephd_mon(int argc, const char **argv)
		auto cct = global_init(&def_args, args,
